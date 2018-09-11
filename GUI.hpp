#include <ncurses.h>
#include <deque>

class GUI
{
public:
  GUI();
  ~GUI();
  void GetInput();
  bool CheckScreenSizeChanged();
  void RefreshDimensions();
  void RefreshTopWindow();
  void RefreshRowWindow();
  void RefreshTrackNumberWindow();
  void RefreshTrackWindows();
private:
  int mScreenWidth;
  int mScreenHeight;
  int mCurrentRow;
  int mFirstTrack;

  /* dimension-specific variables */
  int mOuterBoxPadding;
  int mTracksToShow;
  int mRowsToShow;


  WINDOW* mTopWindow;
  WINDOW* mRowWindow;
  WINDOW* mTrackNumberWindow;
  std::deque<WINDOW *> mTrackWindows;

  
};