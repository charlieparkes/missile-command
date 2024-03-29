
#include "menu.h"

Menu::Menu()
{
	selectedItem = -1;	//nothing return
	menuItemFont = new TextDX();
	menuHeadingFont = new TextDX();
}

void Menu::initialize(Graphics *g, Input *i)
{
	menuHeading ="The Llamas\nAre Coming";
	menuItem1 = "Play";
	menuItem2 = "Disable SoundFX";
	menuItem3 = "Instructions";
	menuItem4 = "Credits";
	menuItem5 = "High Scores";
	highlightColor = graphicsNS::RED;
	normalColor = graphicsNS::WHITE;
	menuAnchor = D3DXVECTOR2(50,380);
	input = i;
	verticalOffset = 40;
	linePtr = 0;
	selectedItem = -1;
	graphics = g;
	menuItemFont = new TextDX();
	menuHeadingFont = new TextDX();
	menuItemFontHighlight = new TextDX();
	if(menuItemFont->initialize(graphics, 25, true, false, "Retro Computer") == false)
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing menuItem font"));
	if(menuItemFontHighlight->initialize(graphics, 28, true, false, "Retro Computer") == false)
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing menuItem font"));
	if(menuHeadingFont->initialize(graphics, 61, true, false, "Retro Computer") == false)
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing menuHeading font"));
	menuHeadingFont->setFontColor(normalColor);
	menuItemFont->setFontColor(graphicsNS::WHITE);
	menuItemFontHighlight->setFontColor(highlightColor);

	upDepressedLastFrame = false;
	downDepressedLastFrame = false;
	enterDepressedLastFrame = false;
}

int Menu::update()
{
	if(input->getMouseLButton()) enterDepressedLastFrame = true;

	int yPos = input->getMouseY();

	if(yPos >= menuAnchor.y&& yPos <= menuAnchor.y + 30)
	{
		selectedItem = 0;
	}

	int foo = verticalOffset;
	if(yPos >= menuAnchor.y + foo && yPos <= menuAnchor.y + foo + 30)
	{
		selectedItem = 1;
	}
	foo = verticalOffset *2;
	if(yPos >= menuAnchor.y + foo && yPos <= menuAnchor.y + foo + 30)
	{
		selectedItem = 2;
	}
	foo = verticalOffset *3;
	if(yPos >= menuAnchor.y + foo && yPos <= menuAnchor.y + foo + 30)
	{
		selectedItem = 3;
	}
	foo = verticalOffset * 4;
	if (yPos >= menuAnchor.y + foo && yPos <= menuAnchor.y + foo + 30)
	{
		selectedItem = 4;
	}



	linePtr = selectedItem;
	if (!input->getMouseLButton() && enterDepressedLastFrame)
	{	
		linePtr = selectedItem;
		if(selectedItem == 1)
		{
			if(menuItem2=="Disable SoundFX")
			{
				menuItem2="Enable SoundFX";
			}
			else if(menuItem2 =="Enable SoundFX")
			{
				menuItem2="Disable SoundFX";
			}
		}

		enterDepressedLastFrame = false;
		return selectedItem;
	}
	else selectedItem = -1;
	return -1;
}

void Menu::displayMenu()
{
	menuHeadingFont->print(menuHeading, 50, 50);
	if (linePtr==0)
		menuItemFontHighlight->print(menuItem1, menuAnchor.x, menuAnchor.y);
	else
		menuItemFont->print(menuItem1, menuAnchor.x, menuAnchor.y);
	int foo = verticalOffset;
	if (linePtr==1)
		menuItemFontHighlight->print(menuItem2, menuAnchor.x, menuAnchor.y+foo);
	else
		menuItemFont->print(menuItem2, menuAnchor.x, menuAnchor.y+foo);
	foo = 2*verticalOffset;
	if (linePtr==2)
		menuItemFontHighlight->print(menuItem3, menuAnchor.x, menuAnchor.y+foo);
	else
		menuItemFont->print(menuItem3, menuAnchor.x, menuAnchor.y+foo);
	foo = 3*verticalOffset;
	if(linePtr==3)
		menuItemFontHighlight->print(menuItem4, menuAnchor.x, menuAnchor.y+foo);
	else
		menuItemFont->print(menuItem4, menuAnchor.x, menuAnchor.y+foo);
	foo = 4*verticalOffset;
	if (linePtr == 4)
		menuItemFontHighlight->print(menuItem5, menuAnchor.x, menuAnchor.y+foo);
	else
		menuItemFont->print(menuItem5, menuAnchor.x, menuAnchor.y+foo);
}