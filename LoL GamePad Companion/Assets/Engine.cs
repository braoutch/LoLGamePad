﻿using UnityEngine;
using System.Collections;

public class Engine : MonoBehaviour
{

	// Use this for initialization
	void Start ()
	{
	
	}
	
	// Update is called once per frame
	void Update ()
	{
	
	}

	public void buttonClic ()
	{
		Debug.Log ("Je lis " + gameObject.GetComponent <ArduinoAutoDetect> ().Read ());
	}
}