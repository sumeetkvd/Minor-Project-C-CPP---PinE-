#include <algorithm>
#include <iostream>
#include <iterator>
#include <map>
#include <memory>
#include <string>
#include <vector>

class pattern_detector
{
public:
	pattern_detector(const std::vector<std::string> & words)
	{
		for (const auto & word : words) {
			node * p = &root_;
			for (const auto & c : word) {
				if (!p->contains(c))
					p->nodes_[c] = std::make_unique<node>();
				p = p->nodes_[c].get();
			}
			p->is_word_ = true;
		}
	}
	bool find_subsequence(string sentence, string pattern) {
	    int n = pattern.length(), m = sentence.length();
	    int i = 0, j = 0;
	    while (i < n && j < m) {
		if (pattern.charAt(i) == sentence.charAt(j))
		    i++;
		j++;
	    }
	    /*If i reaches end of pattern,that mean we found all
	    characters of pattern in sentence,
	    so pattern is subsequence of sentence, else not*/
	    return i == n;
	}
	
	vector<string> fuzzy_pattern(vector<string> s, string word) {
		vector<string> ans;
		int n = s.size();
		for(int i = 0; i < n; i++){
			if(find_subsequence(s[i], word){
				ans.push_back(s[i]);
			}
		   }
		return ans;
	   }
		

	std::vector<std::string> pattern(const std::string & prefix) const
	{
		const node * p = &root_;
		for (const auto & c : prefix) {
			if (!p->contains(c))
				return {};
			p = p->nodes_.at(c).get();
		}

		std::vector<std::string> v;
		find_words(v, p, prefix);
		return v;
	}

private:
	struct node {
		bool contains(char c) const { return nodes_.find(c) != nodes_.end(); }

		std::map<char, std::unique_ptr<node>> nodes_;
		bool is_word_ = false;
	};

	node root_;

	// output parameter `v` to optimize the vector concatenation
	void find_words(
		std::vector<std::string> & v, const node * p, const std::string & prefix) const
	{
		if (p->is_word_)
			v.push_back(prefix);
		for (const auto & [c, n] : p->nodes_)
			find_words(v, p->nodes_.at(c).get(), prefix + c);
	}
};

int main(int, char **)
{
	const auto t = pattern_detector({"This", "is", "a", "string", ".", "Another", "line", "with", "string", ".", "Just", "a", "simple", "line", "."});

	const auto result = t.pattern("Ano");
	std::copy(begin(result), end(result), std::ostream_iterator<std::string>(std::cout, "\n"));
	
	vector<string> s = {"This is a string.",
			"Another line with string.",
			"Just a simple line."
			    };
	vector<string> fuzzy_result = pattern_detector.fuzzy_pattern(s, "si");
	std::copy(begin(fuzzy_result), end(fuzzy_result), std::ostream_iterator<std::string>(std::cout, "\n"));

	return 0;
}
