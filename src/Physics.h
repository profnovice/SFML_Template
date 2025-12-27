#pragma once
#include  "SimpleEntity.h"

namespace Physics {

	Vec2 GetOverlap(SimpEntPtr a, SimpEntPtr b)
	{
		Vec2 overlap(0.0f, 0.0f);
		float deltaX = b->cTransform->pos.x - a->cTransform->pos.x;
		float deltaY = b->cTransform->pos.y - a->cTransform->pos.y;
		overlap.x = (a->cBoundingBox->halfSize.x + b->cBoundingBox->halfSize.x) - std::abs(deltaX);
		overlap.y = (a->cBoundingBox->halfSize.y + b->cBoundingBox->halfSize.y) - std::abs(deltaY);
		return overlap;
	}

	Vec2 GetPreviousOverlap(SimpEntPtr a, SimpEntPtr b)
	{Vec2 overlap(0.0f, 0.0f);
		float deltaX = b->cTransform->previousPos.x - a->cTransform->previousPos.x;
		float deltaY = b->cTransform->previousPos.y - a->cTransform->previousPos.y;
		overlap.x = (a->cBoundingBox->halfSize.x + b->cBoundingBox->halfSize.x) - std::abs(deltaX);
		overlap.y = (a->cBoundingBox->halfSize.y + b->cBoundingBox->halfSize.y) - std::abs(deltaY);
		return overlap;
	}
}