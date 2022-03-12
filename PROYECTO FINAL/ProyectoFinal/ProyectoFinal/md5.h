/**
 * @file md5.h
 * @author Sarmento, Chicaiza
 * @brief  Archivo de cabecera para la clase MD5
 * @version 0.1
 * @date 2022-02-22
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#pragma once

#include <iostream>
#include <string>
#include <string.h>
#include <sstream>
#include <algorithm>
#include <vector>
#include "login.h"
#include "archivo.h"

using namespace std;

/**
 * @brief La funcion SHF permite encriptar la contrase�a ingresada formato MD5
 *
 * @param name
 * @param password
 *
 * @return unsigned int
 */

 //HASH FUCTION
unsigned int SHF(string input) { //SHF = hash fuction
	unsigned int Init = 124564352;
	unsigned int Magic = 5674356;
	unsigned int Hash;
	for (int i = 0; i < input.length(); i++) {
		Hash = Hash ^ (input[i]); //XOR each byte of input
		Hash = Hash * Magic; //Multiply by the magic number
	}
	return Hash;
}

/**
 * @brief La funcion ToHex convierte un numero entero a una cadena de caracteres hexadecimal
 *
 * @param input
 * @return string
 */

string ToHex(unsigned int input) {
	string HexHash;
	stringstream hexstream;
	hexstream << hex << input;
	HexHash = hexstream.str();
	std::transform(HexHash.begin(), HexHash.end(), HexHash.begin(), ::toupper);
	return HexHash;
}

/**
 * @brief La funcion toString imprime los datos de un usuario
 *
 */
void toString() {
	system("cls");
	system("COLOR 7");
	cout << "Su usuario es: " << name << endl;

	cout << "\n\nSu usuario encriptado: " << ToHex(SHF(name)) << endl;
	cout << "Su contraseña: " << ToHex(SHF(pass)) << endl;
}