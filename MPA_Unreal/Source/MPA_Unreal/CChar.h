// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Quirk.h"
#include <map>
#include <functional>

using Mind = std::vector<string>;
using std::map;
using std::pair;
using std::function;



/**
 * 
 */
class MPA_UNREAL_API CChar
{
	// Naming
	string name;
	string fname;
	vector<string> nameParts;
	
	// Inforamation
	Mind knowledge;
	Mind precedents;
	vector<Quirk> knownQuirks;
	Mind items;

	// Attributes
	vector<Quirk> quirks; 
	int bbs = 0;
	int btt = 0;
	int fit = 50;
	int fat = 50;
	bool sex = true; // male

	// relationship stats
	map<string, vector<int>> rels;

	// Private Helper Functions
	void processName(string);
	

public:


	// Public Methods
	bool learn(string);
	bool knows(string); 

	 
	// Getters
	Quirk quirk(string);

	// Constructors
	CChar();
	// name + sex + quirk + body info + weight gain function
	CChar(string, bool, Quirk, map<string, int>, function<void(CChar&, int)>);
	// name + sex + quirks + body info + weight gain function
	CChar(string, bool, vector<Quirk>, map<string, int>, function<void(CChar&, int)>);


	// Operator Overloads
	bool operator==(string);
	CChar& operator+(Quirk);
	void operator++();
	void operator--();

	// Destructor
	~CChar();

};



// Weight Gain Functions
struct wg_TopHeavy {
	void operator()(CChar&, int);
};
struct wg_Distributed{
	void operator()(CChar&, int);
};
struct wg_BottomHeavy{
	void operator()(CChar&, int);
};


