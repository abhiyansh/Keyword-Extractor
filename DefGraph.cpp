template <typename T>
void remove_duplicates(std::vector<T>& vec)
{
  sort(vec.begin(), vec.end());
  vec.erase(unique(vec.begin(), vec.end()), vec.end());
}

//normalises L (axis = 0)
void normalise(vector<vector<double> > &L, int n){	
	for(int i=0;i<n;i++){
		double sum = 0.0;
		for(int j=0;j<n;j++) sum+=L[j][i];
		for(int j=0;j<n;j++) L[j][i]/=sum;
	}
}

tuple<vector<vector<double> >, int, vector<string>> DefGraph(const vector<string> &v){
	vector<string>words = v;
	remove_duplicates(words);
	map<string, unsigned int> word_2_idx;
	for(unsigned int i=0; i < words.size(); i++) word_2_idx.insert({words.at(i), i});

	int n = words.size();
	vector<vector<double> > L(n , vector<double> (n, 0));

	int N = 3, m = v.size();

	string w1, w2;
	unsigned int idx_1, idx_2;

	for(int i=0;i<=m-N;i++){
		for(int j=i;j<i+N;j++){
			w1 = v[i];
			w2 = v[j];
			idx_1 = word_2_idx.find(w1)->second;
			idx_2 = word_2_idx.find(w2)->second;
			
			L[idx_1][idx_2] = 1;
			L[idx_2][idx_1] = 1;
		}
	}

	normalise(L, n);

	return make_tuple(L, n, words);
}