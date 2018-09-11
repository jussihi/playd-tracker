#include "GUI.hpp"


GUI::GUI()
{
  /* Initialize dimensions */
  mOuterBoxPadding = 1;
  mFirstTrack = 1;

  /* Initialize starting row to 0 */
  mCurrentRow = 0;

  /* Initialize screen */
  initscr();

  /* Don't output anything */
  noecho();

  /* Get initial screen size */
  getmaxyx(stdscr, mScreenHeight, mScreenWidth);

  /* Create top window and Initialize (refresh) it */
  mTopWindow = newwin(7, 72, mOuterBoxPadding, mOuterBoxPadding);
  RefreshTopWindow();
  
  /* Create row window and initialize (refresh) it */
  mRowWindow = newwin(5, 4, 9, mOuterBoxPadding);
  RefreshRowWindow();

  /* Create TrackNumberWindow and initialize (refresh) it */
  int x = getmaxx(stdscr);
  mTrackNumberWindow = newwin(1, x - 6, 8, 6);
  RefreshTrackNumberWindow();

  /* Initialize windows with minimum of 4 instrument windows */
  for(int i = 0; i < 4; i++) mTrackWindows.push_back(nullptr);

}


GUI::~GUI()
{
  /* End ncurses */
  endwin();
}


void GUI::GetInput()
{
  getch();

  if(CheckScreenSizeChanged())
  {
    // printw("Size changed!\n");
  }

  

  /* Print something to the screen */
  //printw("Hello World!\n");

  /* Moves the cursor to the desired position */
  //move(2, 5);
  //attron(A_BOLD | A_DIM | A_REVERSE);
  //printw("Hello Again!\n");
  //attroff(A_BLINK);

  /* Loads memory to screen */
  //refresh();

  /* Waits for user input */
  //getch();


  //clear();
  /* New Window pointer */
  // newwin(height, width, start_y, start_x);
}

bool GUI::CheckScreenSizeChanged()
{
  int x, y;
  getmaxyx(stdscr, y, x);

  bool changed = false;
  if(y != mScreenHeight || x != mScreenWidth)
  {
    endwin();
    initscr();
    noecho();
    //clear();
    refresh();
    RefreshDimensions();
    RefreshTopWindow();
    RefreshRowWindow();
    RefreshTrackNumberWindow();
    changed = true;
  }
  return changed;
}

void GUI::RefreshDimensions()
{
  int x = getmaxx(stdscr);
  mTracksToShow = (x-6) / 17;
}


void GUI::RefreshTopWindow()
{
  int y, x;
  getmaxyx(stdscr, y, x);
  wclear(mTopWindow);
  delwin(mTopWindow);

  /* If the screen size is bigger than 74 columns, use max size */
  if(x > 74)
  {
    mTopWindow = newwin(7, x-2, mOuterBoxPadding, mOuterBoxPadding);
  }
  else
  {
    mTopWindow = newwin(7, 72, mOuterBoxPadding, mOuterBoxPadding);
  }
  box(mTopWindow, 0, 0);

  refresh();

  mvwprintw(mTopWindow, 0, 6, "playd trckr V0.01"); 
  mvwprintw(mTopWindow, 0, 32, "Copyright 2018 Jussi Hietanen");

  getmaxyx(mTopWindow, y, x);

  mvwprintw(mTopWindow, 1, 6, "x: %d, y: %d", x, y);
  wrefresh(mTopWindow);
}


void GUI::RefreshRowWindow()
{
  wclear(mRowWindow);
  delwin(mRowWindow);
  mRowWindow = newwin(5, 4, 9, mOuterBoxPadding);
  int y, x;
  getmaxyx(stdscr, y, x);

  /* set basic boundaries for row count, set height here */
  if( y-9 > 64)
  {
    wresize(mRowWindow, 64, 4);
  }
  else
  {
    wresize(mRowWindow, y - 9, 4);
  }
  box(mRowWindow, 0, 0);
  refresh();
  wrefresh(mRowWindow);
}

void GUI::RefreshTrackNumberWindow()
{
  int x = getmaxx(stdscr);
  wclear(mTrackNumberWindow);
  delwin(mTrackNumberWindow);
  mTrackNumberWindow = newwin(1, x - 6, 8, 6);

  
  for(int i = 0; i < mTracksToShow; i++)
  {
    mvwprintw(mTrackNumberWindow, 0, i*17, "     %02d", mFirstTrack + i);
  }
  refresh();
  wrefresh(mTrackNumberWindow);
}

void GUI::RefreshTrackWindows()
{
  /* Check if the number of tracks to be shown has changed */
  if(mTrackWindows.size != mTracksToShow)
  {
    if(mTrackWindows.size > mTracksToShow)
    {

    }
    else
    {

    }
  }

  /* Here load data from tracker side to GUI */

  /* Print the new windows */
  for(int i = 0; i < )
  {
    
  }
}