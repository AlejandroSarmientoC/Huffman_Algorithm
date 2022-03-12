/**
 * @file HuffmanTree.h
 * @author Sarmiento, Chicaiza
 * @brief  Archivo de cabecera para la clase HuffmanTree
 * @version 0.1
 * @date 2022-02-22
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#pragma once

#include <memory>
#include <algorithm>
#include <vector>
#include <sstream>
#include <iostream>
#include <map>
#include "Node.h"

using namespace std;

typedef Node<char> Symbol;
typedef shared_ptr<Symbol> SymbolPtr;

class HuffmanTree
{
public:
	/**
	 * @brief Metodo constructor
	 *
	 */
	HuffmanTree();
	/**
	 * @brief Metodo constructor
	 * 
	 */
	HuffmanTree(const string&);

	/**
	 * @brief Metodo encode()
	 * 
	 * @return string 
	 */
	string encode(const string&) const;
	/**
	 * @brief Metodo decode()
	 * 
	 * @return string 
	 */
	string decode(const string&) const;

private:
	/**
	 * @brief Metodo init()
	 * @param string 
	 *  
	 */
	void init(const string&);
	/**
	 * @brief Metodo create binary tree
	 * 
	 */
	void create_binary_tree(vector<SymbolPtr>&);
	/**
	 * @brief Create hash table
	 * 
	 */
	void create_hash_table(map<char, SymbolPtr>);

	/**
	 * @brief Create a dictionary object
	 * 
	 * @return map<char, SymbolPtr> 
	 */
	map<char, SymbolPtr> create_dictionary(const string&) const;
	/**
	 * @brief Metodo move to vector
	 * 
	 * @return vector<SymbolPtr> 
	 */
	vector<SymbolPtr> move_to_vector(map<char, SymbolPtr>&) const;
	/**
	 * @brief Metodo find path
	 * 
	 * @return string 
	 */
	string find_path(Symbol&, const char&, bool&, const string& = "");
	/**
	 * @brief Metodo find symbol
	 * 
	 * @param long 
	 * @return char 
	 */
	char find_symbol(Symbol&, const char * const, unsigned long&) const;

	SymbolPtr binary_tree;
	map<char, string> hash_table;
};