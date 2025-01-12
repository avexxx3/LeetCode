class Solution {
    struct Time {
        int time;
        bool sit;
        int person;

        Time(int t, bool s, int p): time(t), sit(s), person(p) {}

        bool operator >(Time const& rhs) {
            return time > rhs.time;
        }
    };

    class Comparator {
        public:
        int operator()(Time const& lhs, Time const& rhs) {
            if(rhs.time == lhs.time)
                return lhs.sit;
            return lhs.time > rhs.time;
        }
    };

public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        priority_queue <Time, vector<Time>, Comparator> minHeap;
        int people = times.size();

        for(int i=0; i<people; i++) {
            minHeap.push(Time(times[i][0], 1, i));
            minHeap.push(Time(times[i][1], 0, i));
        }

        vector<int> chairs(people, -1);
        while(true) {
            Time thing = minHeap.top();
            minHeap.pop();
            if(thing.sit)
                for(int& chair: chairs) {
                    if(chair == -1) {
                        chair = thing.person;
                        break;
                    }
                }
            else
                for(int& chair: chairs) {
                    if(chair == thing.person) {
                        chair = -1;
                        break;
                    }
                }
            

            if(thing.person == targetFriend) {
                for(int i=0; i<people; i++)
                    if(chairs[i] == targetFriend)
                        return i;
            }
        }

    }
};