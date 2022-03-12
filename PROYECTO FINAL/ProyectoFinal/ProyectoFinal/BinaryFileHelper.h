/**
 * @file BinaryFileHelper.h
 * @author Sarmiento, Chicaiza
 * @brief  Archivo de cabecera para la clase BinaryFileHelper
 * @version 0.1
 * @date 2022-02-22
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#pragma once

#include <algorithm>
#include <string>
#include <fstream>
#include <iterator>
#include <exception>
#include <vector>
#include <sstream>
#include "TransformUtils.h"

using namespace std;

class BinaryFileHelper
{
public:
	/**
	 * @brief Metodo write()
	 * @param string
	 * @param string
	 */
	static void write(const string&, const vector<unsigned char>&);
	/**
	 * @brief Metodo read()
	 * 
	 * @return string 
	 */
	static string read(const string&, const int = 1000);
	/**
	 * @brief Metodo get file size
	 * 
	 * @param filename 
	 * @return streampos 
	 */
	static streampos get_file_size(const string& filename);

private:
	BinaryFileHelper();
};