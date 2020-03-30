// Fill out your copyright notice in the Description page of Project Settings.

#include "ABCharacter.h"
#include "ABAnimInstance.h"
#include "DrawDebugHelpers.h"


// Sets default values
AABCharacter::AABCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	/*
	*	CreateDefaultSubobject<ExampleClassType>(TEXT("ExampleObjectName"));
	*	������Ʈ ���� �Ҵ�
	*/
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SPRINGARM"));
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("CAMERA"));

	//��Ʈ ������Ʈ(ĸ��)�� ����
	SpringArm->SetupAttachment(GetCapsuleComponent());
	Camera->SetupAttachment(SpringArm);
	
	//�޽��� �⺻ ȸ�� �� ������ ����
	GetMesh()->SetRelativeLocationAndRotation(FVector(0.f, 0.f, -88.f), FRotator(0.f, -90.f, 0.f));

	//������ �� ����
	SpringArm->TargetArmLength = 400.f;
	//������ �� ��ġ
	SpringArm->SetRelativeRotation(FRotator(-15.f, 0.f, 0.f));

	//��θ� ���� ���ҽ� �Ҵ�
	//SkeletalMesh'/Game/InfinityBladeWarriors/Character/CompleteCharacters/SK_CharM_Cardboard.SK_CharM_Cardboard'
	static ConstructorHelpers::FObjectFinder<USkeletalMesh> SK_CARDBOARD(TEXT("/Game/InfinityBladeWarriors/Character/CompleteCharacters/SK_CharM_Cardboard.SK_CharM_Cardboard"));
	if (SK_CARDBOARD.Succeeded())
	{
		GetMesh()->SetSkeletalMesh(SK_CARDBOARD.Object);
	}

	GetMesh()->SetAnimationMode(EAnimationMode::AnimationBlueprint);
	//AnimBlueprint'/Game/Book/Animations/WarriorAnimBlueprint.WarriorAnimBlueprint'
	static ConstructorHelpers::FClassFinder<UAnimInstance> WARRIOR_ANIM(TEXT("/Game/Book/Animations/WarriorAnimBlueprint.WarriorAnimBlueprint_C"));

	if (WARRIOR_ANIM.Succeeded())
	{
		GetMesh()->SetAnimInstanceClass(WARRIOR_ANIM.Class);
	}

	SetControlMode(EControlMode::DIABLO);

	ArmLengthSpeed = 3.f;
	ArmRotationSpeed = 10.f;
	GetCharacterMovement()->JumpZVelocity = 800.f;

	IsAttacking = false;

	MaxCombo = 4;
	AttackEndComboState();

	GetCapsuleComponent()->SetCollisionProfileName(TEXT("ABCharacter"));

	AttackRange = 200.f;
	AttackRadius = 50.f;

	FName WeaponSocket(TEXT("hand_rSocket"));


	ABLOG(Warning, TEXT("aaaaaaaaaaaaaaaaaaaaaaa"));

	if (GetMesh()->DoesSocketExist(WeaponSocket))
	{
		ABLOG(Warning, TEXT("bbbbbbbbbbbbbbbbbbbbb"));

		Weapon = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("WEAPON"));
		//SkeletalMesh'/Game/InfinityBladeWeapons/Weapons/Weapon_ForgingHammers/SK_Forging_Mallet_02.SK_Forging_Mallet_02'
		static ConstructorHelpers::FObjectFinder<USkeletalMesh> SK_WEAPON(TEXT("/Game/InfinityBladeWeapons/Weapons/Weapon_ForgingHammers/SK_Forging_Mallet_02.SK_Forging_Mallet_02"));
		ABLOG(Warning, TEXT("ccccccccccccccccccccc"));
		if (SK_WEAPON.Succeeded())
		{
			ABLOG(Warning, TEXT("ddddddddddddddddddddd"));
			Weapon->SetSkeletalMesh(SK_WEAPON.Object);
		}
		Weapon->SetupAttachment(GetMesh(), WeaponSocket);
	}
}

// Called when the game starts or when spawned
void AABCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

void AABCharacter::SetControlMode(EControlMode NewControlMode)
{
	CurrentControlMode = NewControlMode;

	switch (CurrentControlMode)
	{
	case EControlMode::GTA:
		//SpringArm->TargetArmLength = 450.f;
		//SpringArm->SetRelativeRotation(FRotator::ZeroRotator);
		ArmLengthTo = 450.f;
		SpringArm->bUsePawnControlRotation = true;					//��Ʈ�ѷ��� ���� ī�޶� ���� ȸ����ų ���ΰ�?
		SpringArm->bInheritPitch = true;							//��ġ �ӵ� ���� �޳�?
		SpringArm->bInheritRoll = true;								//�� �ӵ� ���� �޳�?
		SpringArm->bInheritYaw = true;								//��� �ӵ� ���� �޳�?
		SpringArm->bDoCollisionTest = true;							//������ �� ���� �ε����� �� ó�� ����
		bUseControllerRotationYaw = false;							//��Ʈ�ѷ��� ȸ���� ��쿡 ����?

		GetCharacterMovement()->bOrientRotationToMovement = true;			//ĳ������ �̵� �������� �ڵ����� ���� ���� ȸ��?
		GetCharacterMovement()->bUseControllerDesiredRotation = false;		//ĳ������ ȸ�� �ε巴��
		GetCharacterMovement()->RotationRate = FRotator(0.f, 720.f, 0.f);	//ȸ�� �ӵ� ����
		break;
	case EControlMode::DIABLO:
		//SpringArm->TargetArmLength = 800.f;
		//SpringArm->SetRelativeRotation(FRotator(-45.f, 0.f, 0.f));
		ArmLengthTo = 800.f;
		ArmRotationTo = FRotator(-45.f, 0.f, 0.f);
		SpringArm->bUsePawnControlRotation = false;
		SpringArm->bInheritPitch = false;
		SpringArm->bInheritYaw = false;
		SpringArm->bDoCollisionTest = false;
		bUseControllerRotationYaw = false;

		GetCharacterMovement()->bOrientRotationToMovement = false;
		GetCharacterMovement()->bUseControllerDesiredRotation = true;
		GetCharacterMovement()->RotationRate = FRotator(0.f, 720.f, 0.f);
		break;
	}
}

// Called every frame
void AABCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//FInterpTo float�� ���� , RInterpTo Rotator�� ����
	SpringArm->TargetArmLength = FMath::FInterpTo(SpringArm->TargetArmLength, ArmLengthTo, DeltaTime, ArmLengthSpeed);

	switch (CurrentControlMode)
	{
	case EControlMode::GTA:
		break;
	case EControlMode::DIABLO:

		SpringArm->RelativeRotation = FMath::RInterpTo(SpringArm->RelativeRotation, ArmRotationTo, DeltaTime, ArmRotationSpeed);
		// SizeSquared�� ���Ϳ� ���͸� �� ���� ���� �Ÿ��� �����ϴ� �Լ�.
		if (DirectionToMove.SizeSquared() > 0.f)
		{
			//MakeFromX(Vector)�� �� ���� ���͸� ������ �����ϴ� �� ���� ���� �� ����� �� ȸ�� ���� ����.
			GetController()->SetControlRotation(FRotationMatrix::MakeFromX(DirectionToMove).Rotator());
			AddMovementInput(DirectionToMove);
		}
		break;
	}
}

void AABCharacter::PostInitializeComponents()
{
	//PostInitializeComponents()�� �������̵� �� ��� Super�� �� ����� ũ���ð� �� ����.
	Super::PostInitializeComponents();

	ABAnim = Cast<UABAnimInstance>(GetMesh()->GetAnimInstance());
	ABCHECK(nullptr != ABAnim);

	//�ִ� �ν��Ͻ��� �ִԸ�Ÿ�ְ� ������ AddDynamic�� ���� ��������Ʈ ����� �Լ��� �߻���Ŵ
	ABAnim->OnMontageEnded.AddDynamic(this, &AABCharacter::OnAttackMontageEnded);

	ABAnim->OnNextAttackCheck.AddLambda([this]()->void {
		ABLOG(Warning, TEXT("OnNextAttackCheck"));
		CanNextCombo = false;
		if (IsComboInputOn)
		{
			AttackStartComboState();
			ABAnim->JumpToAttackMontageSection(CurrentCombo);
		}
	});

	ABAnim->OnAttackHitCheck.AddUObject(this, &AABCharacter::AttackCheck);
}

float AABCharacter::TakeDamage(float DamageAmount, FDamageEvent const & DamageEvent, AController * EventInstigator, AActor * DamageCauser)
{
	float FinalDamage = Super::TakeDamage(DamageAmount, DamageEvent, EventInstigator, DamageCauser);
	ABLOG(Warning, TEXT("Actor : %s Took Damage : %f"), *GetName(), FinalDamage);

	if (FinalDamage > 0.f)
	{
		ABAnim->SetDeadAnim();
		SetActorEnableCollision(false);
	}

	return FinalDamage;
}

// Called to bind functionality to input
void AABCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis(TEXT("UpDown"), this, &AABCharacter::UpDown);
	PlayerInputComponent->BindAxis(TEXT("LeftRight"), this, &AABCharacter::LeftRight);
	PlayerInputComponent->BindAxis(TEXT("LookUp"), this, &AABCharacter::LookUp);
	PlayerInputComponent->BindAxis(TEXT("Turn"), this, &AABCharacter::Turn);

	PlayerInputComponent->BindAction(TEXT("ViewChange"), EInputEvent::IE_Pressed, this, &AABCharacter::ViewChange);
	PlayerInputComponent->BindAction(TEXT("Jump"), EInputEvent::IE_Pressed, this, &AABCharacter::Jump);
	PlayerInputComponent->BindAction(TEXT("Attack"), EInputEvent::IE_Pressed, this, &AABCharacter::Attack);
}

void AABCharacter::UpDown(float NewAxisValue)
{	
	switch (CurrentControlMode)
	{
	case EControlMode::GTA:
		AddMovementInput(FRotationMatrix(GetControlRotation()).GetUnitAxis(EAxis::X), NewAxisValue);
		break;
	case EControlMode::DIABLO:
		DirectionToMove.X = NewAxisValue;
		break;
	}
}

void AABCharacter::LeftRight(float NewAxisValue)
{
	switch (CurrentControlMode)
	{
	case EControlMode::GTA:
		AddMovementInput(FRotationMatrix(GetControlRotation()).GetUnitAxis(EAxis::Y), NewAxisValue);
		break;
	case EControlMode::DIABLO:
		DirectionToMove.Y = NewAxisValue;
		break;
	}
}

void AABCharacter::LookUp(float NewAxisValue)
{
	switch (CurrentControlMode)
	{
	case EControlMode::GTA:
		AddControllerPitchInput(NewAxisValue);
		break;
	case EControlMode::DIABLO:
		break;
	}
}

void AABCharacter::Turn(float NewAxisValue)
{
	switch (CurrentControlMode)
	{
	case EControlMode::GTA:
		AddControllerYawInput(NewAxisValue);
		break;
	case EControlMode::DIABLO:
		break;
	}
}

void AABCharacter::ViewChange()
{
	switch (CurrentControlMode)
	{
	case EControlMode::GTA:
		GetController()->SetControlRotation(GetActorRotation());
		SetControlMode(EControlMode::DIABLO);
		break;
	case EControlMode::DIABLO:
		GetController()->SetControlRotation(SpringArm->RelativeRotation);
		SetControlMode(EControlMode::GTA);
		break;
	}
}

void AABCharacter::Attack()
{
	//ABLOG_S(Warning);

	//if (IsAttacking) return;

	////auto AnimInstance = Cast<UABAnimInstance>(GetMesh()->GetAnimInstance());
	////if (nullptr == AnimInstance) return;


	//ABAnim->PlayAttackMontage();

	//IsAttacking = true;

	if (IsAttacking)
	{
		ABCHECK(FMath::IsWithinInclusive<int32>(CurrentCombo, 1, MaxCombo));
		if (CanNextCombo)
		{
			IsComboInputOn = true;
		}
	}
	else
	{
		ABCHECK(CurrentCombo == 0);
		AttackStartComboState();
		ABAnim->PlayAttackMontage();
		ABAnim->JumpToAttackMontageSection(CurrentCombo);
		IsAttacking = true;
	}
}

void AABCharacter::OnAttackMontageEnded(UAnimMontage * Montage, bool bInterupted)
{
	ABCHECK(IsAttacking);
	ABCHECK(CurrentCombo > 0);
	IsAttacking = false;
	AttackEndComboState();
}

void AABCharacter::AttackStartComboState()
{
	CanNextCombo = true;
	IsComboInputOn = false;
	//FMath::IsWithinInclusive<Type>(Ȯ���� ����, �ּҰ�, �ִ밪) Ȯ���� ������ �ּҰ�~�ִ밪 ���� ������ �Ǻ��ϴ� �Լ�
	ABCHECK(FMath::IsWithinInclusive<int32>(CurrentCombo, 0, MaxCombo - 1));
	CurrentCombo = FMath::Clamp<int32>(CurrentCombo + 1, 1, MaxCombo);
}

void AABCharacter::AttackEndComboState()
{
	IsComboInputOn = false;
	CanNextCombo = false;
	CurrentCombo = 0;
}

void AABCharacter::AttackCheck()
{
	FHitResult HitResult;
	FCollisionQueryParams Params(NAME_None, false, this);
	bool bResult = GetWorld()->SweepSingleByChannel(
		HitResult,												//HitResult (�浹 ��� ����ü)
		GetActorLocation(),										//Start (Ž�� ���� ��ġ)
		GetActorLocation() + GetActorForwardVector() * 200.f,	//End (Ž�� ���� ��ġ)
		FQuat::Identity,										//Rot (Ž���� ���� ȸ��)
		ECollisionChannel::ECC_GameTraceChannel12,				//�浹 ���� Ʈ���̽� ä��
		FCollisionShape::MakeSphere(50.f),						//Ž�� ��� ���� �� ����ü
		Params);												//Ž�� ���� ���� ����ü
	
#if ENABLE_DRAW_DEBUG

	FVector TraceVec = GetActorForwardVector() * AttackRange;
	FVector Center = GetActorLocation() + TraceVec * 0.5f;
	float HalfHeight = AttackRange * 0.5f + AttackRadius;
	FQuat CapsuleRot = FRotationMatrix::MakeFromZ(TraceVec).ToQuat();
	FColor DrawColor = bResult ? FColor::Green : FColor::Red;
	float DebugLifeTime = 5.f;

	DrawDebugCapsule(GetWorld(),	// ����			
		Center,						// �׸� ���� �߽���
		HalfHeight,					// ����
		AttackRadius,				// �ݰ�
		CapsuleRot,					// ȸ����
		DrawColor,					// ��
		false,						// �۽ý��Ͻ� ����
		DebugLifeTime);				// �׸��� �ð�
#endif

	if (bResult)
	{
		if (HitResult.Actor.IsValid())
		{
			ABLOG(Warning, TEXT("Hit Actor Name : %s"), *HitResult.Actor->GetName());

			FDamageEvent DamageEvent;
			//TakeDamage(��������ġ, ������ ����(�̺�Ʈ), ������(��Ʈ�ѷ�), �����ڵ���(�� �Ǵ� ����))
			HitResult.Actor->TakeDamage(50.f, DamageEvent, GetController(), this);
		}
	}
}

