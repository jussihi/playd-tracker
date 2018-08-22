#include <ncurses.h>
#include <deque>

class GUI
{
public:
  GUI();
  ~GUI();
  void GetInput();
  bool CheckScreenSizeChanged();
  void RefreshTopWindow();
  void RefreshRowWindow();
private:
  int mScreenWidth;
  int mScreenHeight;
  int mCurrentRow;

  WINDOW* mTopWindow;
  WINDOW* mRowWindow;
  WINDOW* mTrackNumberWindow;
  std::deque<WINDOW *> mTrackWindows;
};