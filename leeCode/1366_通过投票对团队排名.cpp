#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

struct Team {
    char name;
    std::vector<int> rankInfo;
};

using TeamTable = std::vector<Team>;

class Solution {
public:
    string rankTeams(vector<string>& votes)
    {
        if (votes.empty() || votes[0].empty())
            return rankInfo;

        GenerateTeamInfo(votes);
        SortTeams();
        OutputTeamRank();
        return rankInfo;
    }

private:
    void GenerateTeamInfo(const vector<string>& votes);
    void SortTeams();
    void OutputTeamRank();

    TeamTable teams;
    string rankInfo;
};

void Solution::GenerateTeamInfo(const vector<string>& votes)
{
    const size_t teamNum = votes[0].size();
    const string& firstVote = votes[0];
    teams.resize(teamNum);
    for (size_t i = 0; i < teamNum; ++i) {
        teams[i].name = firstVote[i];
        teams[i].rankInfo.resize(teamNum);
    }

    for (Team& t : teams) {
        for (const string& vote : votes) {
            const size_t rank = vote.find(t.name);
            ++t.rankInfo[rank];
        }
    }
}

void Solution::SortTeams()
{
    std::stable_sort(teams.begin(), teams.end(),
                    [] (const Team& a, const Team& b) {return a.name < b.name;});

    for (size_t rank = teams.size(); rank > 0; -- rank) {
        std::stable_sort(teams.begin(), teams.end(),
                        [rank] (const Team& a, const Team& b) {return a.rankInfo[rank - 1] > b.rankInfo[rank - 1];});
    }
}

void Solution::OutputTeamRank()
{
    for (Team& t : teams) {
        rankInfo += t.name;
    }
}

int main() {
    std::vector<string> votes{"BCA", "CAB", "CBA", "ABC", "ACB", "BAC"};
    Solution a;
    cout << a.rankTeams(votes) << endl;
    return 0;
}
