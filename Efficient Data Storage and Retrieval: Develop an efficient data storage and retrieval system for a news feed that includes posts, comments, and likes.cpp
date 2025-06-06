#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

struct Post {
    int postId;
    string content;
    vector<string> comments;
    int likes;

    Post(int id, string txt) {
        postId = id;
        content = txt;
        likes = 0;
    }
};

unordered_map<int, Post> newsFeed;

void addPost(int id, string text) {
    newsFeed[id] = Post(id, text);
}

void addComment(int id, string comment) {
    newsFeed[id].comments.push_back(comment);
}

void likePost(int id) {
    newsFeed[id].likes++;
}

void showFeed() {
    for (auto& p : newsFeed) {
        cout << "Post ID: " << p.second.postId << ", Text: " << p.second.content << "\n";
        cout << "Likes: " << p.second.likes << "\nComments:\n";
        for (string c : p.second.comments)
            cout << "- " << c << "\n";
        cout << "---------------------\n";
    }
}

int main() {
    addPost(1, "Hello World!");
    addComment(1, "Nice post");
    likePost(1);
    likePost(1);
    addPost(2, "Another Post!");
    showFeed();
    return 0;
}
