#include "GUI.hpp"


int main(int argc, char** argv)
{

  GUI* TrackerGui = new GUI();
  while(true)
  {
    TrackerGui->GetInput();
  }
  delete TrackerGui;
  return 0;
}