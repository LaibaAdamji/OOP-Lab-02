#include <iostream>
#include <string>
using namespace std;


class MediaFile {
protected:
    string filePath;
    double size;

public:
    MediaFile(const string& path, double sz) : filePath(path), size(sz) {}

    virtual void play() {
        cout << "Playing media file: " << filePath << endl;
    }

    virtual void stop() {
        cout << "Stopping media file: " << filePath << endl;
    }

    virtual void displayInfo() const {
        cout << "File Path: "<< filePath << ", Size: " << size << " MB" << endl;
    }
};

class VisualMedia : virtual public MediaFile {
protected:
    int resolutionWidth;
    int resolutionHeight;

public:
    VisualMedia(const string& path, double sz, int width, int height)
        : MediaFile(path, sz), resolutionWidth(width), resolutionHeight(height) {}

    void displayInfo() const override {
        MediaFile::displayInfo();
        cout << "Resolution: " << resolutionWidth << "x" << resolutionHeight << endl;
    }
};

// Intermediate class AudioMedia
class AudioMedia : virtual public MediaFile {
protected:
    int sampleRate;

public:
    AudioMedia(const string& path, double sz, int rate)
        : MediaFile(path, sz), sampleRate(rate) {}

    void displayInfo() const override {
        MediaFile::displayInfo();
        cout << "Sample Rate: " << sampleRate << " Hz" << endl;
    }
};

class VideoFile : public VisualMedia, public AudioMedia {
public:
    VideoFile(const string& path, double sz, int width, int height, int rate)
        : MediaFile(path, sz), VisualMedia(path, sz, width, height), AudioMedia(path, sz, rate) {}

    void displayInfo() const override {
        VisualMedia::displayInfo();
        cout << "Sample Rate: " << sampleRate << " Hz" << endl;
    }
};

// Derived class ImageFile (inherits from VisualMedia)
class ImageFile : public VisualMedia {
public:
    ImageFile(const string& path, double sz, int width, int height)
        : MediaFile(path, sz), VisualMedia(path, sz, width, height) {}
};

// Derived class AudioFile (inherits from AudioMedia)
class AudioFile : public AudioMedia {
public:
    AudioFile(const string& path, double sz, int rate)
        : MediaFile(path, sz), AudioMedia(path, sz, rate) {}
};

int main() {

    VideoFile video("video.mp4", 500, 1920, 1080, 48000);
    ImageFile image("image.jpg", 10, 800, 600);
    AudioFile audio("audio.mp3", 5, 44100);

    MediaFile* mediaFiles[] = {&video, &image, &audio};

    for (MediaFile* media : mediaFiles) {
        media->displayInfo();
        media->play();
        media->stop();
        cout << endl;
    }

    return 0;
}
