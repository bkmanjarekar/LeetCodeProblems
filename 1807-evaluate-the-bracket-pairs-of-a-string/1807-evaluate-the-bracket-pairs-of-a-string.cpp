#include <unordered_map>
#include <regex>

class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        std::unordered_map<string, string>dict;
        dict.reserve(knowledge.size()); 

        for (const auto& pair : knowledge) 
        {            
            dict[pair[0]] = pair[1];            
        }

        string result = "";
        string key = "";
        bool in_parentheses = false;

        // 3. Single-pass linear scan (Replaces slow std::regex)
        for (char c : s) {
            if (c == '(') {
                in_parentheses = true;
                key.clear(); // Reset key buffer
            } 
            else if (c == ')') {
                in_parentheses = false;
                auto it = dict.find(key);
                if (it != dict.end()) {
                    result += it->second;
                } else {
                    result += '?';
                }
            } 
            else {
                if (in_parentheses) {
                    key += c; // Build the key character by character
                } else {
                    result += c; // Directly append normal text
                }
            }
        }
        
        return result;  
    }
};