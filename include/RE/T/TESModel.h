#pragma once

#include "RE/BSCore/BSFixedString.h"
#include "RE/FormComponents/BaseFormComponent.h"


namespace RE
{
	namespace BSResource
	{
		struct ID;
	}


	class TESModelTextureSwap;


	class TESModel : public BaseFormComponent
	{
	public:
		inline static constexpr auto RTTI = RTTI_TESModel;


		virtual ~TESModel();  // 00

		// override (BaseFormComponent)
		virtual void InitializeDataComponent() override;				// 01
		virtual void ClearDataComponent() override;						// 02
		virtual void CopyComponent(BaseFormComponent* a_rhs) override;	// 03

		// add
		virtual const char*			 GetModel() const;				 // 04 - { return model.c_str(); }
		virtual void				 SetModel(const char* a_model);	 // 05 - { model = a_model; }
		virtual TESModelTextureSwap* GetAsModelTextureSwap();		 // 06 - { return 0; }


		// members
		BSFixedString	model;		  // 08 - MODL
		BSResource::ID* textures;	  // 10 - MODT
		std::uint32_t*	addons;		  // 18
		std::uint16_t	numTextures;  // 20
		std::uint16_t	numAddons;	  // 22
		std::uint32_t	pad24;		  // 24
	};
	static_assert(sizeof(TESModel) == 0x28);
}