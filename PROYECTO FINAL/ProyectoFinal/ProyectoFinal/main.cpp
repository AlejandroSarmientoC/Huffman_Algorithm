#include <engine.h>
#include <iostream>
#include <limits>
#include <conio.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <cmath>
#include "menu.h"
#include "menu_option.h"
#include "HuffmanTree.h"
#include "TransformUtils.h"
#include "BinaryFileHelper.h"
#include "archivo.h"
#include "md5.h"
#include "login.h"

#pragma comment ( lib, "libmat.lib" )
#pragma comment ( lib, "libmx.lib" )
#pragma comment ( lib, "libmex.lib" )
#pragma comment ( lib, "libeng.lib" )


using namespace std;

int main()
{
	Menu m("\t\tMENU COMPRESOR HUFFMAN");
	char op;

	registro();

	m.add_option(MenuOption("\tComprimir Archivo", [&](MenuOptionArguments args) {
		system("cls");

		std::cout << "Comprimiento" << endl;
		try
		{
			const auto input = "prueba.txt";
			const auto output = "compressPrueba.bin";

			ifstream file(input);
			if (!file.is_open()) throw exception("Exception: Unable to open file.");

			stringstream stream;
			stream << file.rdbuf();
			file.close();

			const auto file_content = stream.str();
			const auto file_size = BinaryFileHelper::get_file_size(input);
			std::cout << "Before compression: " << file_size << " bytes" << endl;

			HuffmanTree huffman_tree(file_content);
			const auto encoded = huffman_tree.encode(file_content);
			const auto bytes = TransformUtils::transform_string_to_bytes(encoded);

			BinaryFileHelper::write(output, bytes);
			const auto after_size = BinaryFileHelper::get_file_size(output);
			const auto delta = file_size - after_size;

			std::cout << "After compression: " << after_size << " bytes" << endl;
			std::cout << "Tiempo de ejecicion: (" << static_cast<double>(delta) / file_size << ")" << endl;

			const auto output_data = BinaryFileHelper::read(output);


			std::cout << "Desea descomprimir el archivo? (s/n)" << endl;
			cin >> op;

			if (op == 's' || op == 'S') {
				std::cout << huffman_tree.decode(output_data);
			}
		}
		catch (exception& e)
		{
			std::cout << e.what() << endl;
		}
		cin.get();
		return 0;

	}));
	m.add_option(MenuOption("\tGraficas de Matlab", [&](MenuOptionArguments args) {
		system("cls");

		std::cout << "Graficas" << endl;
		Engine *m_pEngine;
		m_pEngine = engOpen("null");

		const int arraySize = 20;
		const double degTorad = .0245;

		double SinArray[arraySize];
		double CosArray[arraySize];
		double TanArray[arraySize];
		double Degrees[arraySize];

		for (int iii = 0; iii < arraySize; iii++) {
			Degrees[iii] = iii;
			SinArray[iii] = sin(iii*degTorad);
			CosArray[iii] = cos(iii*degTorad);
			TanArray[iii] = tan(iii*degTorad);
		}
		mxArray* SIN = mxCreateDoubleMatrix(arraySize, 1, mxREAL);
		std::memcpy((void *)mxGetPr(SIN), (void *)SinArray, sizeof(double)* arraySize);
		engPutVariable(m_pEngine, "SinGraph", SIN);

		mxArray* COS = mxCreateDoubleMatrix(arraySize, 1, mxREAL);
		std::memcpy((void *)mxGetPr(SIN), (void *)SinArray, sizeof(double)*arraySize);
		engPutVariable(m_pEngine, "CosGraph", SIN);

		mxArray* TAN = mxCreateDoubleMatrix(arraySize, 1, mxREAL);
		std::memcpy((void *)mxGetPr(TAN), (void *)TanArray, sizeof(double)*arraySize);
		engPutVariable(m_pEngine, "TanGraph", TAN);

		mxArray* DEG = mxCreateDoubleMatrix(arraySize, 1, mxREAL);
		std::memcpy((void *)mxGetPr(DEG), (void *)Degrees, sizeof(double)*arraySize);
		engPutVariable(m_pEngine, "Degrees", DEG);


		engEvalString(m_pEngine, "figure('units','normalized','outerposition',[0 0 0 1 1 1]),");
		engEvalString(m_pEngine, "plot(Degrees,TanGraph,'r',Degrees,CosGraph,'b'), grind minor, title('Matlab Plot'),");

		std::cout << "Tiempo de ejecucion de las funciones " << endl;
		std::cout << get1() << endl;
		std::cout << get2() << endl;
		return 0;

	}));
	m.add_option(MenuOption("\tDatos de usuario", [&](MenuOptionArguments args) {
		toString();
		system("pause");
		return 0;
	}));
	m.add_option(MenuOption("\tSalir", [&](MenuOptionArguments args) {
		std::cout << "Salio con exito del programa..." << std::endl;
		m.stop();
	}, false));

	m.display();
}
