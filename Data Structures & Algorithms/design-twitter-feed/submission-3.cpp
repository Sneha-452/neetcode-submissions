class Twitter {
public:

    // userId -> set of users whom he follows
    unordered_map<int, unordered_set<int>> following;

    // userId -> list of {time, tweetId}
    unordered_map<int, vector<pair<int, int>>> tweets;

    int time = 0;

    Twitter() {
    }

    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({time++, tweetId});
    }

    vector<int> getNewsFeed(int userId) {
        vector<pair<int, int>> allTweets;

        // User's own tweets
        for (auto tweet : tweets[userId]) {
            allTweets.push_back(tweet);
        }

        // Tweets of followed users
        for (int followee : following[userId]) {
            for (auto tweet : tweets[followee]) {
                allTweets.push_back(tweet);
            }
        }

        // Latest tweets first
        sort(allTweets.begin(), allTweets.end(),
             [](auto &a, auto &b) {
                 return a.first > b.first;
             });

        vector<int> feed;

        // Only latest 10
        for (int i = 0; i < min(10, (int)allTweets.size()); i++) {
            feed.push_back(allTweets[i].second);
        }

        return feed;
    }

    void follow(int followerId, int followeeId) {
        if (followerId == followeeId)
            return;

        following[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {
        following[followerId].erase(followeeId);
    }
};