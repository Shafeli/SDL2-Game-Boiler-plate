#include "CollisionDection.h"
#include "GameObject.h"

//Did Object Hit Object
////////////////////////////////////////////////////////
bool CollisionDection::DoesObjectOverlap(const ObjectVector& listOne, const ObjectVector& listTwo)
{
	//loops over sprites if two touch mark for death & sends to cleaner
	for (const auto& i : listOne)
	{
		for (const auto& j : listTwo)
		{
			//if (i->GetSprite().getGlobalBounds().intersects(j->GetSprite().getGlobalBounds()))
			//{
			//	i->MarkedForDeath();
			//	j->MarkedForDeath();
			//	return true;
			//}
		}
	}
	return false;
}
