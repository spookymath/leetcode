class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) 
    {
        vector<string> v = {".-",   // a
                            "-...", // b
                            "-.-.", // c
                            "-..",  // d
                            ".",    // e
                            "..-.", // f
                            "--.",  // g
                            "....", // h
                            "..",   // i
                            ".---", // j
                            "-.-",  // k
                            ".-..", // l
                            "--",   // m
                            "-.",   // n
                            "---",  // o
                            ".--.", // p
                            "--.-", // q
                            ".-.",  // r
                            "...",  // s
                            "-",    // t
                            "..-",  // u
                            "...-", // v
                            ".--",  // w
                            "-..-", // x
                            "-.--", // y
                            "--.."};// z
        
        set<string> st;
        for(int i=0; i<words.size(); i++)
        {
            string str = "";
            for(int j=0; j<words[i].size(); j++)
                str.append(v[words[i][j] - 'a']);
            
            st.insert(str);
        }
        
        return st.size();
    }
};
