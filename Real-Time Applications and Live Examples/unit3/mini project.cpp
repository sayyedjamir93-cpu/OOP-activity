#include <iostream>
#include <string>
#include <vector>
using namespace std;
// Base Class: Media
class Media
{
protected:
    string title;
    string durationOrSize;

public:
    // Constructor
    Media(string t, string ds) : title(t), durationOrSize(ds) {}

    virtual void play() = 0;
    virtual void pause() = 0;
    virtual void stop() = 0;

    // Virtual function to display common details
    virtual void showDetails() const
    {
        cout << "Title: " << title << " | Info: " << durationOrSize;
    }
    virtual ~Media() {}
};
class Audio : public Media
{
private:
    string artist;

public:
    Audio(string t, string duration, string a)
        : Media(t, duration), artist(a) {}
    void play() override
    {
        cout << "[Playing Audio] Playing song: " << title << " by " << artist << endl;
    }
    void pause() override
    {
        cout << "[Paused Audio] " << title << " is paused." << endl;
    }
    void stop() override
    {
        cout << "[Stopped Audio] " << title << " stopped." << endl;
    }
    void showDetails() const override
    {
        cout << "Type: Audio | ";
        Media::showDetails();
        cout << " | Artist: " << artist << endl;
    }
};
class Video : public Media
{
private:
    string resolution;

public:
    Video(string t, string duration, string res)
        : Media(t, duration), resolution(res) {}
    void play() override
    {
        cout << "[Playing Video] Playing video: " << title << " (" << resolution << ")" << endl;
    }
    void pause() override
    {
        cout << "[Paused Video] " << title << " video playback paused." << endl;
    }
    void stop() override
    {
        cout << "[Stopped Video] " << title << " video stopped." << endl;
    }
    void showDetails() const override
    {
        cout << "Type: Video | ";
        Media::showDetails();
        cout << " | Resolution: " << resolution << endl;
    }
};
class Image : public Media
{
private:
    string dimensions;

public:
    Image(string t, string size, string dim)
        : Media(t, size), dimensions(dim) {}
    void play() override
    {
        cout << "[Displaying Image] Opening image: " << title << " (" << dimensions << ")" << endl;
    }
    void pause() override
    {
        cout << "[Image Viewer] Image slideshow paused." << endl;
    }
    void stop() override
    {
        cout << "[Image Viewer] Closed image: " << title << endl;
    }
    void showDetails() const override
    {
        cout << "Type: Image | ";
        Media::showDetails();
        cout << " | Dimensions: " << dimensions << endl;
    }
};

int main()
{
    cout << "=================================================================" << endl;
    cout << "           MEDIA PLAYER WITH POLYMORPHIC CONTROLS       " << endl;
    cout << "=================================================================" << endl
         << endl;

    // Collection of Base-Class Pointers
    vector<Media *> playlist;
    playlist.push_back(new Audio("Rangrezz", "4:15 mins", "Arijit Singh"));
    playlist.push_back(new Video("C++ Tutorial", "15:30 mins", "1080p Full HD"));
    playlist.push_back(new Image("Sunset_Photo", "2.5 MB", "1920x1080"));

    cout << "--- PLAYLIST DETAILS ---" << endl;
    for (const auto item : playlist)
    {
        item->showDetails();
    }
    cout << "\n--------- DEMONSTRATING MEDIA CONTROLS " << endl;
    for (const auto item : playlist)
    {
        cout << "---------------------------------" << endl;
        item->play();
        item->pause();
        item->stop();
    }
    cout << "---------------------------------" << endl;
    for (auto item : playlist)
    {
        delete item;
    }
    cout << "\n----------------------------------------------------------------" << endl;
    return 0;
}