//==============================================================================================================
//-----------------------------------_heightBounds[]_IS_THE_SCENE_CENTER_POINT(O,O,O)---------------------------
//==============================================================================================================
void o1_HEIGHT_GROUP_FUNCTION(void)
{
    if(o1_isActive == true)
    {
        for(int i = 0; i < 8; i++)
        {
            if((o1_HEIGHT_GROUP[i][0] + moveSet[0]) < heightBounds[0] && (o1_HEIGHT_GROUP[i][0] + moveSet[0]) > -heightBounds[0] && (o1_HEIGHT_GROUP[i][1] + moveSet[1]) < heightBounds[1] && (o1_HEIGHT_GROUP[i][1] + moveSet[1]) > -heightBounds[1]) 
            {
                groundLevelAdjust           += o1_HEIGHT_GROUP[i][2]; //_ADD_THE_HEIGHT_FOR_EACH_SPHERE_IN_THE_CHARACTER'S_ZONE
                groundLevel_SpheresActive   += 1;                     //_DIVIDE_THE_CUMULATIVE_HEIGHTS_OF_ALL_DETECTED_SPHERES_BY_THIS_COUNTER_TO_OBTAIN_THE_AVERAGE_BY_WHICH_TO_ADJUST-> moveSet[2](height)
            }
        }
    }
}
//==============================================================================================================
//-----------------------------------_heightBounds[]_IS_THE_SCENE_CENTER_POINT(O,O,O)---------------------------
//==============================================================================================================
void o2_HEIGHT_GROUP_FUNCTION(void)
{
    if(o2_isActive == true)
    {
        for(int i = 0; i < 15; i++)
        {
            if((o2_HEIGHT_GROUP[i][0] + moveSet[0]) < heightBounds[0] && (o2_HEIGHT_GROUP[i][0] + moveSet[0]) > -heightBounds[0] && (o2_HEIGHT_GROUP[i][1] + moveSet[1]) < heightBounds[1] && (o2_HEIGHT_GROUP[i][1] + moveSet[1]) > -heightBounds[1]) 
            {
                groundLevelAdjust           += o2_HEIGHT_GROUP[i][2]; //_ADD_THE_HEIGHT_FOR_EACH_SPHERE_IN_THE_CHARACTER'S_ZONE
                groundLevel_SpheresActive   += 1;                     //_DIVIDE_THE_CUMULATIVE_HEIGHTS_OF_ALL_DETECTED_SPHERES_BY_THIS_COUNTER_TO_OBTAIN_THE_AVERAGE_BY_WHICH_TO_ADJUST-> moveSet[2](height)
            }
        }
    }
}
//==============================================================================================================
//-----------------------------------_heightBounds[]_IS_THE_SCENE_CENTER_POINT(O,O,O)---------------------------
//==============================================================================================================
void o3_HEIGHT_GROUP_FUNCTION(void)
{
    if(o3_isActive == true)
    {
        for(int i = 0; i < 17; i++)
        {
            if((o3_HEIGHT_GROUP[i][0] + moveSet[0]) < heightBounds[0] && (o3_HEIGHT_GROUP[i][0] + moveSet[0]) > -heightBounds[0] && (o3_HEIGHT_GROUP[i][1] + moveSet[1]) < heightBounds[1] && (o3_HEIGHT_GROUP[i][1] + moveSet[1]) > -heightBounds[1]) 
            {
                groundLevelAdjust           += o3_HEIGHT_GROUP[i][2]; //_ADD_THE_HEIGHT_FOR_EACH_SPHERE_IN_THE_CHARACTER'S_ZONE
                groundLevel_SpheresActive   += 1;                     //_DIVIDE_THE_CUMULATIVE_HEIGHTS_OF_ALL_DETECTED_SPHERES_BY_THIS_COUNTER_TO_OBTAIN_THE_AVERAGE_BY_WHICH_TO_ADJUST-> moveSet[2](height)
            }
        }
    }
}
//==============================================================================================================
//-----------------------------------_heightBounds[]_IS_THE_SCENE_CENTER_POINT(O,O,O)---------------------------
//==============================================================================================================
void o4_HEIGHT_GROUP_FUNCTION(void)
{
    if(o4_isActive == true)
    {
        for(int i = 0; i < 10; i++)
        {
            if((o4_HEIGHT_GROUP[i][0] + moveSet[0]) < heightBounds[0] && (o4_HEIGHT_GROUP[i][0] + moveSet[0]) > -heightBounds[0] && (o4_HEIGHT_GROUP[i][1] + moveSet[1]) < heightBounds[1] && (o4_HEIGHT_GROUP[i][1] + moveSet[1]) > -heightBounds[1]) 
            {
                groundLevelAdjust           += o4_HEIGHT_GROUP[i][2]; //_ADD_THE_HEIGHT_FOR_EACH_SPHERE_IN_THE_CHARACTER'S_ZONE
                groundLevel_SpheresActive   += 1;                     //_DIVIDE_THE_CUMULATIVE_HEIGHTS_OF_ALL_DETECTED_SPHERES_BY_THIS_COUNTER_TO_OBTAIN_THE_AVERAGE_BY_WHICH_TO_ADJUST-> moveSet[2](height)
            }
        }
    }
}
//==============================================================================================================
//-----------------------------------_heightBounds[]_IS_THE_SCENE_CENTER_POINT(O,O,O)---------------------------
//==============================================================================================================
void o5_HEIGHT_GROUP_FUNCTION(void)
{
    if(o5_isActive == true)
    {
        for(int i = 0; i < 12; i++)
        {
            if((o5_HEIGHT_GROUP[i][0] + moveSet[0]) < heightBounds[0] && (o5_HEIGHT_GROUP[i][0] + moveSet[0]) > -heightBounds[0] && (o5_HEIGHT_GROUP[i][1] + moveSet[1]) < heightBounds[1] && (o5_HEIGHT_GROUP[i][1] + moveSet[1]) > -heightBounds[1]) 
            {
                groundLevelAdjust           += o5_HEIGHT_GROUP[i][2]; //_ADD_THE_HEIGHT_FOR_EACH_SPHERE_IN_THE_CHARACTER'S_ZONE
                groundLevel_SpheresActive   += 1;                     //_DIVIDE_THE_CUMULATIVE_HEIGHTS_OF_ALL_DETECTED_SPHERES_BY_THIS_COUNTER_TO_OBTAIN_THE_AVERAGE_BY_WHICH_TO_ADJUST-> moveSet[2](height)
            }
        }
    }
}
//==============================================================================================================
//-----------------------------------_heightBounds[]_IS_THE_SCENE_CENTER_POINT(O,O,O)---------------------------
//==============================================================================================================
void o6_HEIGHT_GROUP_FUNCTION(void)
{
    if(o6_isActive == true)
    {
        for(int i = 0; i < 10; i++)
        {
            if((o6_HEIGHT_GROUP[i][0] + moveSet[0]) < heightBounds[0] && (o6_HEIGHT_GROUP[i][0] + moveSet[0]) > -heightBounds[0] && (o6_HEIGHT_GROUP[i][1] + moveSet[1]) < heightBounds[1] && (o6_HEIGHT_GROUP[i][1] + moveSet[1]) > -heightBounds[1]) 
            {
                groundLevelAdjust           += o6_HEIGHT_GROUP[i][2]; //_ADD_THE_HEIGHT_FOR_EACH_SPHERE_IN_THE_CHARACTER'S_ZONE
                groundLevel_SpheresActive   += 1;                     //_DIVIDE_THE_CUMULATIVE_HEIGHTS_OF_ALL_DETECTED_SPHERES_BY_THIS_COUNTER_TO_OBTAIN_THE_AVERAGE_BY_WHICH_TO_ADJUST-> moveSet[2](height)
            }
        }
    }
}
//==============================================================================================================
//-----------------------------------_heightBounds[]_IS_THE_SCENE_CENTER_POINT(O,O,O)---------------------------
//==============================================================================================================
void o7_HEIGHT_GROUP_FUNCTION(void)
{
    if(o7_isActive == true)
    {
        for(int i = 0; i < 6; i++)
        {
            if((o7_HEIGHT_GROUP[i][0] + moveSet[0]) < heightBounds[0] && (o7_HEIGHT_GROUP[i][0] + moveSet[0]) > -heightBounds[0] && (o7_HEIGHT_GROUP[i][1] + moveSet[1]) < heightBounds[1] && (o7_HEIGHT_GROUP[i][1] + moveSet[1]) > -heightBounds[1]) 
            {
                groundLevelAdjust           += o7_HEIGHT_GROUP[i][2]; //_ADD_THE_HEIGHT_FOR_EACH_SPHERE_IN_THE_CHARACTER'S_ZONE
                groundLevel_SpheresActive   += 1;                     //_DIVIDE_THE_CUMULATIVE_HEIGHTS_OF_ALL_DETECTED_SPHERES_BY_THIS_COUNTER_TO_OBTAIN_THE_AVERAGE_BY_WHICH_TO_ADJUST-> moveSet[2](height)
            }
        }
    }
}
