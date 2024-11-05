#include "Track.h"

Track::Track()
{
    m_title = "Lucky";
    m_composer = "Jason Mraz";
}

Track::operator string() const
{
    return "Song " + m_title + "composed by " + m_composer; 
}