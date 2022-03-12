/**
 * @file Node.h
 * @author Sarmiento, Chicaiza
 * @brief 
 * @version 0.1
 * @date 2022-02-22
 * 
 * @copyright Copyright (c) 2022
 * 
 */


#pragma once

#include <memory>

using std::shared_ptr;

template<typename T>
class Node
{
public:
	/**
	 * @brief Metodo constructor
	 * 
	 * @param value 
	 */
	Node(const T);
	/**
	 * @brief Metodo constructor
	 * 
	 * @param value 
	 * @param left 
	 * @param right 
	 */
	Node(const T, const int);
	/**
	 * @brief Metodo constructor
	 * 
	 * @param value 
	 * @param left 
	 * @param right 
	 * @param parent 
	 */
	Node(const int);
	/**
	 * @brief Metodo constructor
	 * 
	 * @param value 
	 * @param left 
	 * @param right 
	 * @param parent 
	 */
	Node(const int, const shared_ptr<Node>&, const shared_ptr<Node>&);
	/**
	 * @brief Get the count object
	 * 
	 * @return int 
	 */
	int get_count() const;
	/**
	 * @brief Get the value object
	 * 
	 * @return T 
	 */
	T get_value() const;
	/**
	 * @brief Get the left object
	 * 
	 * @return shared_ptr<Node> 
	 */
	bool has_left() const;
	/**
	 * @brief Get the right object
	 * 
	 * @return shared_ptr<Node> 
	 */
	bool has_right() const;
	const shared_ptr<Node<T>>& get_left() const;
	const shared_ptr<Node<T>>& get_right() const;
	Node& operator ++ ();

private:
	shared_ptr<Node<T>> left;
	shared_ptr<Node<T>> right;

	int count;
	T value;
};