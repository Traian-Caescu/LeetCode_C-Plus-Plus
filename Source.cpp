class Solution {
public:
    string findReplaceString(string s, vector<int>& indices, vector<string>& sources, vector<string>& targets) {
        int n = indices.size();

        for (int i = 0; i < n; ++i) {
            // Skip invalid indices
            if (indices[i] == -1) continue;

            // Check if the source matches the substring at the index
            if (s.substr(indices[i], sources[i].size()) == sources[i]) {
                // Perform the replacement
                s.replace(indices[i], sources[i].size(), targets[i]);

                // Adjust indices for subsequent replacements
                int diff = targets[i].size() - sources[i].size();
                for (int j = i + 1; j < n; ++j) {
                    if (indices[j] == indices[i]) {
                        indices[j] = -1; // Mark the overlapping index as processed
                    }
                    else if (indices[j] > indices[i]) {
                        indices[j] += diff; // Adjust the index if needed
                    }
                }
            }
        }

        return s;
    }
};
