/**
 * @file login.h
 * @author Sarmento, Chicaiza
 * @brief  Archivo de cabecera para la clase Login
 * @version 0.1
 * @date 2022-02-22
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#pragma once

#include <iostream>
#include <string.h>
#include <conio.h>
#include "archivo.h"
#include "md5.h"

using namespace std;

double a = 0, b = 0, a1 = 0, b1 = 0, r0 = 0, r1 = 0;

/**
 * @brief El metodo registration es el encargado de registrar un usuario en el sistema
 *
 */
void registration() {
	a = clock();
	int v = 0;
	system("cls");
	fflush(stdin);
	std::cout << "\tRegistration" << endl;
	fflush(stdin);
	std::cout << "\nName: ";
	cin >> name;
	//system("pause");
	fflush(stdin);
	std::cout << "Password: ";
	for (int i = 0; i < 60; i++) {
		v = _getch();
		if ((v >= 48 && v <= 57) || (v >= 65 && v <= 90) || (v >= 97 && v <= 122)) {
			aux_pass[i] = v;
			std::cout << "*";
		}
		else if (v == 13) {
			aux_pass[i] = '\0';
			break;
		}
	}
	pass = aux_pass;

	//cin.getline(pass, 100, '\n');
	fflush(stdin);
	insert(name, pass);
	b = clock();
	r0 = (b - a) / CLOCKS_PER_SEC;
}

/**
 * @brief El metodo login() permite ingresar al sistema
 *
 */
void login() {
	do {
		system("cls");
		std::cout << "\n\tLOG IN" << endl;
		fflush(stdin);
		std::cout << "\nName: ";
		cin >> nameaux;
		fflush(stdin);
		std::cout << "Password: ";
		for (int i = 0; i < 60; i++) {
			int v = _getch();
			if ((v >= 48 && v <= 57) || (v >= 65 && v <= 90) || (v >= 97 && v <= 122)) {
				passaux[i] = v;
				std::cout << "*";
			}
			else if (v == 13) {
				passaux[i] = '\0';
				break;
			}
		}
		fflush(stdin);
		if (strcmp(nameaux, name) == 0 && strcmp(passaux, pass) == 0) {
			std::cout << "\n\tWelcome " << name << endl;
			break;
		}
		else if (readfile(nameaux, passaux)) {
			std::cout << "\n\tWelcome " << nameaux << endl;
			system("pause");
			break;
		}
		else {
			std::cout << "\n\tWrong name or password" << endl;
			system("pause");
		}
		system("pause");
	} while (true);
}

/**
 * @brief El metodo registro() da la opcion de loguearse o registrarse
 *
 */
void registro() {
	a1 = clock();
	int option;
	char answer;

	system("cls");

	std::cout << "\t\nBIENVENIDO\n\n";
	std::cout << "1. Registrarse\n";
	std::cout << "2. Ingresar\n";
	std::cout << "3. Salir\n";
	std::cout << "Ingrese su opcion: ";
	cin >> option;

	switch (option) {
	case 1:
		registration();
		std::cout << "\nDo you want to sign in? (y/n): ";
		cin >> answer;
		if (answer == 'y' || answer == 'Y') {
			login();
			system("pause");
		}
		else {
			exit(1);
		}
		break;
	case 2:
		login();
		system("pause");
		break;
	case 3:
		std::cout << "\n\tGoodbye" << endl;
		exit(1);
		break;
	}
	b1 = clock();
	r1 = (b1 - a1) / CLOCKS_PER_SEC;
}

double get1() {
	return r0;
}
double get2() {
	return r1;
}