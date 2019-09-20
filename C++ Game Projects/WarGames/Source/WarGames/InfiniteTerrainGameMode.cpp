// Fill out your copyright notice in the Description page of Project Settings.


#include "InfiniteTerrainGameMode.h"
#include "Navmesh/NavMeshBoundsVolume.h"
#include "EngineUtils.h"
#include "ActorPool.h"

AInfiniteTerrainGameMode::AInfiniteTerrainGameMode()
{
	NavMeshBV = CreateDefaultSubobject<UActorPool>(FName("Nav Mesh Bounds Volume Pool"));
}

void AInfiniteTerrainGameMode::PopulateBoundsVolumePool()
{
	auto VolumeIterator = TActorIterator<ANavMeshBoundsVolume>(GetWorld());
	while (VolumeIterator)
	{
		AddToPool(*VolumeIterator);
		++VolumeIterator;
	}
}
void AInfiniteTerrainGameMode::AddToPool(ANavMeshBoundsVolume *VolumeToAdd)
{
	NavMeshBV->AddActor(VolumeToAdd);
}