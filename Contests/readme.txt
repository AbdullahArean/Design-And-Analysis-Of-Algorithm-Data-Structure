git clone https://github.com/rachitiitr/CodeforcesContestBot.git
cd CodeforcesContestBot
npm install
export CF_CONTEST=https://codeforces.com/contest/1330
node script.js
./runall.sh A #if you want to test A/sol.cpp
./runall.sh D #if you want to test D/sol.cpp against your output vs sample output
# this will run your code on downloaded test cases
# and print to console your output vs expected output