/* Miscellaneous functions get dumped here*/

/*===Include===*/
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/Text.hpp>
#include <sstream>
#include <string>
#include <unistd.h>
#include <dirent.h>
#include <vector>
#include <random>

// gets working dir from the file its called in
inline std::string GetWorkingDirectory()
{
    char cwd[1024];
    if(!getcwd(cwd, sizeof(cwd))) return "";
    return std::string(cwd) + std::string("/");
}

inline std::vector<std::string> GetFileList
(//params
    const std::string& l_directory,
    const std::string& l_search = "*.*"
)
{//fn body
    std::vector<std::string> files;

    DIR *dpdf;
    dpdf = opendir(l_directory.c_str());
    if (!dpdf) return files;
    if(l_search.empty()) return files;
    std::string search = l_search;
    if (search[0] == '*') search.erase(search.begin());
    if (search[search.length() - 1] == '*') search.pop_back();
    struct dirent *edpf;
    while (edpf = readdir(dpdf))
    {
        std::string name = edpf -> d_name;
        if(edpf-> d_type == DT_DIR) continue;
        if(l_search != "*.*") {
            if (name.length() < search.length()) continue;
            if (search[0] == '.'){
                if (name.compare(name.length() - search.length(), search.length(), search) != 0) continue;
            } else if (name.find(search) == std::string::npos) {
                continue;
            }
        }
        files.emplace_back(name);
    }
    closedir(dpdf);
    return files;
}

inline void ReadQuotedString(std::stringstream& l_stream, std::string& l_string)
{
l_stream >> l_string;
if (l_string.at(0) == '"'){
    while (l_string.at(l_string.length() - 1) != '"' ||
        !l_stream.eof())
    {
        std::string str;
        l_stream >> str;
        l_string.append(" " + str);
    }
}
    l_string.erase(std::remove(
    l_string.begin(), l_string.end(), '"'), l_string.end());
}

template<class T>
inline T Interpolate(float tBegin, float tEnd, const T& begin_val, const T& end_val, float tX)
{
    return static_cast<T>((
        ((end_val - begin_val) / (tEnd - tBegin)) * (tX - tBegin)) + begin_val);
}

inline float GetSFMLMaxTextHeight(const sf::Text& l_text)
{
    auto charSize = l_text.getCharacterSize();    
    auto font = l_text.getFont();
    auto string = l_text.getString().toAnsiString();
    bool bold = (l_text.getStyle() & sf::Text::Bold);
    float max = 0.f;

    for (size_t i = 0; i < string.length(); ++i){
        sf::Uint32 character = string[i];
        auto gylph = font->getGlyph(character, charSize, bold);
        auto height = gylph.bounds.height;
        if (height <= max) continue;
        max = height;
    }
    return max;
}

inline void CenterSFMLText(sf::Text& l_text)
{
    sf::FloatRect rect = l_text.getLocalBounds();
    auto maxHeight = GetSFMLMaxTextHeight(l_text);
    l_text.setOrigin(
        rect.left + (rect.width * 0.5f),
        rect.top + ((maxHeight >= rect.height ?
            maxHeight * 0.5f : rect.height * 0.5f)));
}
