class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        unordered_set<string> s;
        sort(folder.begin(), folder.end());

        vector<string> ans;

        for(const auto& sub_folder : folder){

            int l = 0;
            int r = 2;
            bool flag = false;
            string temp = "";
            string folder = "";
            istringstream data(sub_folder);
            while(getline(data ,folder, '/' )){
                
                if (folder.empty()) continue;
                temp += "/";
                temp += folder;
                

                if(s.find(temp)  != s.end()){
                    flag = true;
                    break;
                }
                
                l += 2;
            }


            if(!flag){
                ans.push_back(sub_folder);
                s.insert(sub_folder);
            }else{
                
            }
            

            
        }

        return ans;
        
    }
};