#include<bits/stdc++.h>
#include<fstream>

using namespace std;

//local files
#include "Tokenize.cpp"
#include "DefGraph.cpp"
#include "wordrank.cpp"
#include "output.cpp"

int main(int argc, char** argv){
	//read, write addresses
	string input_address = argv[1];
	// string output_address = argv[2];
	
	//read input file and tokenize it into words
	vector<string> v = Tokenize(input_address);

	vector<vector<double> > L;
	vector<string> words;
	int n;

	tie(L, n, words) = DefGraph(v);

	//number of words in output
	int T = 5;

	vector<unsigned int> final_indices = RankWords(L, n, T);

	output(words, final_indices);

	return 0;
}