// Fill out your copyright notice in the Description page of Project Settings.

#include "ABAnimInstance.h"

UABAnimInstance::UABAnimInstance()
{
	CurrentPawnSpeed = 0.f;
	IsInAir = false;
}

void UABAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);

	//�� ��ü�� ��ȿ���� �˻� �ϴ� �Լ� ��ȿ�ϸ� �ش� ��ü�� �����Ѵ�.
	auto Pawn = TryGetPawnOwner();
	if (::IsValid(Pawn))
	{
		CurrentPawnSpeed = Pawn->GetVelocity().Size();

		auto Character = Cast<ACharacter>(Pawn);
		if (Character)
		{
			IsInAir = Character->GetCharacterMovement()->IsFalling();
		}
	}
}
