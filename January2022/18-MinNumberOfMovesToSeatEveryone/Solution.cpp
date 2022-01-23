// O(NlogN) Time & O(1) Space
int minMovesToSeat(vector<int> &seats, vector<int> &students)
{
    sort(seats.begin(), seats.end());
    sort(students.begin(), students.end());
    int cnt = 0;
    for (int i = 0; i < seats.size(); ++i)
        cnt += abs(students[i] - seats[i]);
    return cnt;
}