class CfgPatches
{
    class ZellnoVanillaHillAssist
    {
        units[] = {};
        weapons[] = {};
        requiredVersion = 0.1;

        requiredAddons[] =
        {
            "DZ_Vehicles_Wheeled",
            "DZ_Sounds_Effects"
        };
    };
};

class CfgVehicles
{
    class CarScript;

    class Truck_01_Base: CarScript
    {
        class SimulationModule
        {
            class Engine
            {
                torqueCurve[] =
                {
                    650,0,
                    1000,320,
                    1800,430,
                    3500,440,
                    5500,390,
                    7500,300,
                    9000,190,
                    10000,0
                };

                inertia = 0.65;
                frictionTorque = 180;
                rollingFriction = 2.0;
                viscousFriction = 0.6;

                rpmIdle = 800;
                rpmMin = 900;
                rpmClutch = 1400;
                rpmRedline = 10000;
            };

            class Clutch
            {
                maxTorqueTransfer = 720;
                uncoupleTime = 0.08;
                coupleTime = 0.18;
            };

            class Gearbox
            {
                reverse = 20.93;

                ratios[] =
                {
                    9.5,
                    6.0,
                    4.3,
                    3.2
                };
            };
        };
    };

    class OffroadHatchback: CarScript
    {
        class SimulationModule
        {
            class Engine
            {
                torqueCurve[] =
                {
                    650,0,
                    900,120,
                    1800,190,
                    3200,220,
                    4500,210,
                    6000,125,
                    7000,55,
                    8000,0
                };
            };

            class Clutch
            {
                maxTorqueTransfer = 480;
            };
        };
    };


    class CivilianSedan: CarScript
    {
        class SimulationModule
        {
            class Engine
            {
                torqueCurve[] =
                {
                    400,0,
                    900,190,
                    1700,270,
                    2800,320,
                    3800,315,
                    4700,265,
                    5500,140,
                    6000,0
                };
            };

            class Clutch
            {
                maxTorqueTransfer = 600;
            };
        };
    };

    class Sedan_02: CarScript
    {
        class SimulationModule
        {
            class Engine
            {
                torqueCurve[] =
                {
                    600,0,
                    1000,130,
                    1800,200,
                    3000,230,
                    4200,220,
                    5750,170,
                    6500,90,
                    7000,0
                };
            };

            class Clutch
            {
                maxTorqueTransfer = 460;
            };
        };
    };

    class Hatchback_02: CarScript
    {
        class SimulationModule
        {
            class Engine
            {
                torqueCurve[] =
                {
                    850,0,
                    1150,150,
                    2000,270,
                    3500,300,
                    5200,250,
                    6250,140,
                    7000,70,
                    7500,0
                };
            };

            class Clutch
            {
                maxTorqueTransfer = 600;
            };
        };
    };

    class Offroad_02: CarScript
    {
        class SimulationModule
        {
            class Engine
            {
                torqueCurve[] =
                {
                    525,0,
                    1000,330,
                    1300,480,
                    2500,600,
                    3600,550,
                    5120,0
                };
            };

            class Clutch
            {
                coupleTime = 0.25;
            };
        };
    };
};

class CfgSoundShaders
{
    class baseEngineLoud_SoundShader;

    class Truck_01_Engine_Ext_Rpm0_SoundShader: baseEngineLoud_SoundShader
    	{
    		samples[]=
    		{
    			
    			{
    				"\DZ\sounds\vehicles\truck_01\Truck_01_Engine_Ext_Rpm0",
    				1
    			}
    		};
    		frequency="0.95 * (0.56 * (800 + ((rpm - 800) / 5.75)) + 245 + 100 * thrust) / 650";
    		volume="1.4 * 0.9 * (0.6 + 0.4 * ((800 + ((rpm - 800) / 5.75)) factor[1000,3000])) * engineOn * 0.5 * ((0.56 * (800 + ((rpm - 800) / 5.75)) + 245 + 100 * thrust) factor [(680 + 40),(680 - 40)]) * (1 - 0.4 * (1 - campos))";
    	};

    class Truck_01_Engine_Ext_Rpm1_SoundShader: baseEngineLoud_SoundShader
    	{
    		samples[]=
    		{
    			
    			{
    				"\DZ\sounds\vehicles\truck_01\Truck_01_Engine_Ext_Rpm1",
    				1
    			}
    		};
    		frequency="0.95 * (0.56 * (800 + ((rpm - 800) / 5.75)) + 245 + 100 * thrust) / 770";
    		volume="1.4 * 0.9 * (0.6 + 0.4 * ((800 + ((rpm - 800) / 5.75)) factor[1000,3000])) * (thrust factor[0.1,0.45]) * (0.8 + 0.2 * (speed factor [10,60])) * engineOn * 1.1 * ((0.56 * (800 + ((rpm - 800) / 5.75)) + 245 + 100 * thrust) factor [(680 - 40),(680 + 40)]) * ((0.56 * (800 + ((rpm - 800) / 5.75)) + 245 + 100 * thrust) factor [(925 + 262),(925 - 262)]) * (1 - 0.4 * (1 - campos))";
    	};

    class Truck_01_Engine_Offload_Ext_Rpm1_SoundShader: baseEngineLoud_SoundShader
    	{
    		samples[]=
    		{
    			
    			{
    				"\DZ\sounds\vehicles\truck_01\Truck_01_Engine_Ext_Offload_Rpm1",
    				1
    			}
    		};
    		frequency="0.95 * (0.56 * (800 + ((rpm - 800) / 5.75)) + 245 + 100 * thrust) / 770";
    		volume="1.2 * 0.9 * (0.6 + 0.4 * ((800 + ((rpm - 800) / 5.75)) factor[1000,3000])) * (thrust factor[0.6,0.2]) * (0.8 + 0.2 * (speed factor [10,60])) * engineOn * 1.1 * ((0.56 * (800 + ((rpm - 800) / 5.75)) + 245 + 100 * thrust) factor [(680 - 40),(680 + 40)]) * ((0.56 * (800 + ((rpm - 800) / 5.75)) + 245 + 100 * thrust) factor [(925 + 262),(925 - 262)]) * (1 - 0.4 * (1 - campos))";
    	};

    class Truck_01_Engine_Ext_Rpm2_SoundShader: baseEngineLoud_SoundShader
    	{
    		samples[]=
    		{
    			
    			{
    				"\DZ\sounds\vehicles\truck_01\Truck_01_Engine_Ext_Rpm2",
    				1
    			}
    		};
    		frequency="0.95 * (0.56 * (800 + ((rpm - 800) / 5.75)) + 245 + 100 * thrust) / 1100";
    		volume="1.4 * 0.9 * (0.6 + 0.4 * ((800 + ((rpm - 800) / 5.75)) factor[1000,3000])) * (thrust factor[0.1,0.45]) * (0.8 + 0.2 * (speed factor [10,60])) * engineOn * 1.2 * ((0.56 * (800 + ((rpm - 800) / 5.75)) + 245 + 100 * thrust) factor [(925 - 262),(925 + 262)]) * ((0.56 * (800 + ((rpm - 800) / 5.75)) + 245 + 100 * thrust) factor [(1200 + 150),(1200 - 150)]) * (1 - 0.4 * (1 - campos))";
    	};

    class Truck_01_Engine_Offload_Ext_Rpm2_SoundShader: baseEngineLoud_SoundShader
    	{
    		samples[]=
    		{
    			
    			{
    				"\DZ\sounds\vehicles\truck_01\Truck_01_Engine_Ext_Offload_Rpm2",
    				1
    			}
    		};
    		frequency="0.95 * (0.56 * (800 + ((rpm - 800) / 5.75)) + 245 + 100 * thrust) / 1100";
    		volume="1.2 * 0.9 * (0.6 + 0.4 * ((800 + ((rpm - 800) / 5.75)) factor[1000,3000])) * (thrust factor[0.6,0.2]) * (0.8 + 0.2 * (speed factor [10,60])) * engineOn * 1.2 * ((0.56 * (800 + ((rpm - 800) / 5.75)) + 245 + 100 * thrust) factor [(925 - 262),(925 + 262)]) * ((0.56 * (800 + ((rpm - 800) / 5.75)) + 245 + 100 * thrust) factor [(1200 + 150),(1200 - 150)]) * (1 - 0.4 * (1 - campos))";
    	};

    class Truck_01_Engine_Ext_Rpm3_SoundShader: baseEngineLoud_SoundShader
    	{
    		samples[]=
    		{
    			
    			{
    				"\DZ\sounds\vehicles\truck_01\Truck_01_Engine_Ext_Rpm3",
    				1
    			}
    		};
    		frequency="0.95 * (0.56 * (800 + ((rpm - 800) / 5.75)) + 245 + 100 * thrust) / 1300";
    		volume="1.4 * 0.9 * (0.6 + 0.4 * ((800 + ((rpm - 800) / 5.75)) factor[1000,3000])) * (thrust factor[0.1,0.45]) * (0.8 + 0.2 * (speed factor [10,60])) * engineOn * 1.0 * ((0.56 * (800 + ((rpm - 800) / 5.75)) + 245 + 100 * thrust) factor [(1200 - 150),(1200 + 150)]) * ((0.56 * (800 + ((rpm - 800) / 5.75)) + 245 + 100 * thrust) factor [(1410 + 165),(1410 - 165)]) * (1 - 0.4 * (1 - campos))";
    	};

    class Truck_01_Engine_Offload_Ext_Rpm3_SoundShader: baseEngineLoud_SoundShader
    	{
    		samples[]=
    		{
    			
    			{
    				"\DZ\sounds\vehicles\truck_01\Truck_01_Engine_Ext_Offload_Rpm3",
    				1
    			}
    		};
    		frequency="0.95 * (0.56 * (800 + ((rpm - 800) / 5.75)) + 245 + 100 * thrust) / 1300";
    		volume="1.2 * 0.9 * (0.6 + 0.4 * ((800 + ((rpm - 800) / 5.75)) factor[1000,3000])) * (thrust factor[0.6,0.2]) * (0.8 + 0.2 * (speed factor [10,60])) * engineOn * 1.0 * ((0.56 * (800 + ((rpm - 800) / 5.75)) + 245 + 100 * thrust) factor [(1200 - 150),(1200 + 150)]) * ((0.56 * (800 + ((rpm - 800) / 5.75)) + 245 + 100 * thrust) factor [(1410 + 165),(1410 - 165)]) * (1 - 0.4 * (1 - campos))";
    	};

    class Truck_01_Engine_Ext_Rpm4_SoundShader: baseEngineLoud_SoundShader
    	{
    		samples[]=
    		{
    			
    			{
    				"\DZ\sounds\vehicles\truck_01\Truck_01_Engine_Ext_Rpm4",
    				1
    			}
    		};
    		frequency="0.95 * (0.56 * (800 + ((rpm - 800) / 5.75)) + 245 + 100 * thrust) / 1560";
    		volume="1.4 * 0.9 * (0.6 + 0.4 * ((800 + ((rpm - 800) / 5.75)) factor[1000,3000])) * (thrust factor[0.1,0.45]) * (0.8 + 0.2 * (speed factor [10,60])) * engineOn * 0.8 * ((0.56 * (800 + ((rpm - 800) / 5.75)) + 245 + 100 * thrust) factor [(1410 - 165),(1410 + 165)]) * (1 - 0.4 * (1 - campos))";
    	};

    class Truck_01_Engine_Offload_Ext_Rpm4_SoundShader: baseEngineLoud_SoundShader
    	{
    		samples[]=
    		{
    			
    			{
    				"\DZ\sounds\vehicles\truck_01\Truck_01_Engine_Ext_Offload_Rpm4",
    				1
    			}
    		};
    		frequency="0.95 * (0.56 * (800 + ((rpm - 800) / 5.75)) + 245 + 100 * thrust) / 1560";
    		volume="1.2 * 0.9 * (0.6 + 0.4 * ((800 + ((rpm - 800) / 5.75)) factor[1000,3000])) * (thrust factor[0.6,0.2]) * (0.8 + 0.2 * (speed factor [10,60])) * engineOn * 0.8 * ((0.56 * (800 + ((rpm - 800) / 5.75)) + 245 + 100 * thrust) factor [(1410 - 165),(1410 + 165)]) * (1 - 0.4 * (1 - campos))";
    	};


	class Truck_01_Engine_Ext_Broken_SoundShader: baseEngineLoud_SoundShader
		{
			samples[]=
			{
				
				{
					"\DZ\sounds\vehicles\shared\add_layers\Truck_01_Engine_Ext_Broken",
					1
				}
			};
			frequency=0.94999999;
			volume="3 * 0.9 * (0.6 + 0.4 * ((800 + ((rpm - 800) / 5.75)) factor[1000,3000])) * (0.8 + 0.2 * (speed factor [10,60])) * engineOn * 0.8 * ((0.56 * (800 + ((rpm - 800) / 5.75)) + 245 + 100 * thrust) factor [(1410 - 165),(1410 + 165)]) * ((1 - 0.25*doors) max campos) * ((800 + ((rpm - 800) / 5.75)) factor[2000,4000]) * (1 - 0.4 * (1 - campos))";
		};

};
