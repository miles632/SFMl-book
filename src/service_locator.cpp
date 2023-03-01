class Window;
class EventManager;
class TextureManager;
class FontManager;  

struct SharedContext{
    SharedContext():
        m_p_wind(nullptr),
        m_p_eventManager(nullptr),
        m_p_textureManager(nullptr), // m_p_ in this case stands for member and pointer
        m_p_fontManager(nullptr) {}
   
    Window* m_p_wind;
    EventManager* m_p_eventManager;
    TextureManager* m_p_textureManager;
    FontManager* m_p_fontManager;
};
