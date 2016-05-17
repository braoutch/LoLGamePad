//USE MONO 2.0 INSTEAD OF 2.0SUBSET !!!
using UnityEngine;
using System.Collections;
using System.Collections.Generic;
using System.IO.Ports;
using System;
using System.IO;

public class ArduinoAutoDetect : MonoBehaviour
{
	public List<SerialPort> serialPortList = new List<SerialPort> ();
	//Every SerialPort we can open
	int closedPorts = 0;
	private string code = "206";
	SerialPort monSerialPort;

	void Start ()
	{
		Debug.Log ("Recherche de la Griffe...");
		try {
			monSerialPort = FindOpenPorts (code);
			monSerialPort.Open ();
		} catch {
		}
		Debug.Log ("FAIL !");
	}

	SerialPort FindOpenPorts (string arduinoCode)
	{
		SerialPort stream;
		var devices = SerialPort.GetPortNames ();

		if (devices.Length == 0) {
			// try manual enumeration
			devices = System.IO.Directory.GetFiles ("/dev/");
			Debug.Log ("No ports found with GetPortNames");
		}

		Debug.Log (devices.Length + " port(s) série trouvé(s)");

		for (int j = 0; j < devices.Length; j++) {
			//Debug.Log (devices [j]);
		}
		//Try to open every port
		for (int i = 0; i < devices.Length; i++) {

			try {
				stream = new SerialPort (devices [i], 115200);
				stream.Open ();
				if (WhichSerialPortAreU (stream, arduinoCode)) {
					return stream;
				}
			} catch (Exception e) {
				closedPorts++;
				continue;
			}
			if (stream.IsOpen && !devices [i].Contains ("Bluetooth")) {
				Debug.Log ("Port " + i + " is open , named " + devices [i]);
				serialPortList.Add (stream);

				stream.Close ();
			} else
				continue;


		}
		Debug.Log (closedPorts + " ports série fermés.");
		return null;
	}

	public bool WhichSerialPortAreU (SerialPort stream, string arduinoCode)
	{

		try {
			stream.ReadTimeout = 50;
			string serialReadTest = stream.ReadLine ();
			if (String.CompareOrdinal (serialReadTest.Substring (0, 3), arduinoCode) == 0) {
				Debug.Log ("here you are ! bloody " + stream);
				return true;

			} else {
				Debug.Log ("Mauvais code : " + serialReadTest.Substring (0, 3) + ", on cherchait le code " + arduinoCode);
			}
		} catch (TimeoutException) {
			Debug.Log ("Timeout !");
		}

		return false;
	}

	public void Write (string stringToWrite)
	{
		monSerialPort.Write ("#" + stringToWrite);
	}

	public string Read ()
	{
		return  monSerialPort.ReadLine ().Substring (3);
	}

	void OnApplicationQuit ()
	{
		monSerialPort.Close ();
	}
}
