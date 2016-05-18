using UnityEngine;
using System.Collections;
using System;
using UnityEngine.UI;

public class Engine : MonoBehaviour
{
	bool detected = false;
	string currentLine = "";
	public GameObject[] dots = new GameObject[2];
	public Text currentModeText;
	public Text gamePadStatusText;
	ArduinoAutoDetect arduino;

	// Use this for initialization
	void Start ()
	{
		ActivateDots (false);
		arduino = gameObject.GetComponent<ArduinoAutoDetect> ();
	}
	
	// Update is called once per frame
	void Update ()
	{
		//Etat du Gamepad
		if (ArduinoAutoDetect.detected && !detected)
			ActivateDots (true);

		if (detected) {

			//Ligne actuelle
			currentLine = arduino.Read ();

			//Mode actuel du gamepad
			GuessPadMode ();
		}
	}

	public void buttonClic (int mode)
	{	
		if (detected) {
			Debug.Log ("Lancement du mode " + mode.ToString ());
			arduino.Write (mode.ToString ());
		}

	}

	void ActivateDots(bool b)
	{
		dots [0].SetActive (b);
		dots [1].SetActive (!b);
		if (b)
			gamePadStatusText.text = "La Griffe est connectée";
		else
			gamePadStatusText.text = "La Griffe est déconnectée";
	}

	void GuessPadMode(){
		
		string modeName;

		if (String.CompareOrdinal (currentLine, "0") == 0)
			modeName = "Standard";
		if (String.CompareOrdinal (currentLine, "1") == 0)
			modeName = "Vladimir";
		else
			modeName = "en erreur";
		currentModeText.text = "Mode " + modeName;


	}

}
