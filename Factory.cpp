#include "Factory.h"
#include <iostream>

//int Factory::layoutId = 0;

std::unique_ptr<Interface> Factory::CreateLayout(Layouts layoutId)
{
	switch (layoutId)
	{
	case Layouts::LayoutHorizontal:
	{
		return std::make_unique<LayoutHorizontalView>();
	} break;
	case Layouts::LayoutVertical:
	{
		return std::make_unique<LayoutVerticalView>();
	} break;
	case Layouts::LayoutCircleCards:
	{
		return std::make_unique<LayoutCircleCardsView>();
	} break;
	default: break;
	}
}
