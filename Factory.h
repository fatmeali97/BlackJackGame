#pragma once
#include <SDL.h>
#include <memory>
#include "Interface.h"
#include "LayoutHorizontalView.h"
#include "LayoutVerticalView.h"
#include "LayoutCircleCardsView.h"

enum class Layouts : int
{
	LayoutHorizontal = 0,
	LayoutVertical,
	LayoutCircleCards,
	MaxLayoutCount
};

class Factory
{
public:
	static std::unique_ptr<Interface> CreateLayout(Layouts layoutId);
};


