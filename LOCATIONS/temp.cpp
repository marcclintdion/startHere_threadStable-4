//================================================================================
//----------------------------------__GLOBALS__----------------------------------
//================================================================================
#ifdef __APPLE__
//==================================
GLfloat   o3_HEIGHT_GROUP[17][4] = 
{
    {110.0, 114.0, 60.0, 9.0},  //_posX_posY_posZ_RADIUS
    {100.0, 145.0, 50.0, 9.0},
    {140.0, 155.0, 60.0, 9.0},
    {150.0, 115.0, 24.0, 9.0},  
    {110.0, 114.0, 60.0, 9.0}, 
    {100.0, 145.0, 50.0, 9.0},
    {140.0, 155.0, 60.0, 9.0},
    {150.0, 115.0, 24.0, 9.0},      
    {110.0, 114.0, 60.0, 9.0}, 
    {100.0, 145.0, 50.0, 9.0},
    {140.0, 155.0, 60.0, 9.0},
    {150.0, 115.0, 24.0, 9.0},      
    {110.0, 114.0, 60.0, 9.0}, 
    {100.0, 145.0, 50.0, 9.0},
    {140.0, 155.0, 60.0, 9.0},
    {150.0, 115.0, 24.0, 9.0},      
    {150.0, 115.0, 24.0, 9.0},        
};
//==================================
GLuint   o3_HEIGHT_GROUP_TOTAL[17];
GLuint   groundLevel_SpheresActive =     0;
GLfloat  groundLevelAdjust         =     0.0;




//================================================================================
//----------------------------------__INITIALIZE__--------------------------------
//================================================================================




//================================================================================
//----------------------------------__RUN_LOOP__----------------------------------
//================================================================================




void o3_HEIGHT_GROUP_FUNCTION(void)
{

    if(o3_isActive == true)
    {
        for(GLuint i = 0.0; i < o3_HEIGHT_GROUP_TOTAL); i++)
        {
            if((o3_HEIGHT_GROUP[i][0] + moveSet[0]) < heightBounds[0] && (o3_HEIGHT_GROUP[i][0] + moveSet[0]) > -heightBounds[0] && (o3_HEIGHT_GROUP[i][1] + moveSet[1]) < heightBounds[1] && (o3_HEIGHT_GROUP[i][1] + moveSet[1]) > -heightBounds[1])         
            {
                groundLevelAdjust           += o3_HEIGHT_GROUP[i][2]; //_ADD_THE_HEIGHT_FOR_EACH_SPHERE_IN_THE_CHARACTER'S_ZONE
                groundLevel_SpheresActive   += 1;                     //_DIVIDE_THE_CUMULATIVE_HEIGHTS_OF_ALL_DETECTED_SPHERES_BY_THIS_COUNTER_TO_OBTAIN_THE_AVERAGE_BY_WHICH_TO_ADJUST-> moveSet[2](height)

            }//_END-[if()]

        }//_END-[for()]
    

    }//_END-[if()] 

}//_END-[void o3_HEIGHT_GROUP(void)]



//================================================================================
//----------------------------------__FINAL_MOVESET_CALCULATION__-----------------
//================================================================================

adjustMoveSet_HEIGHT = groundLevelAdjust / groundLevel_SpheresActive; //_AVERAGE_OF_ALL_DETECTED_SPHERES_FOR_ALL_ACTIVE_AREAS


moveSet[2] = currentSetHeight + adjustMoveSet_HEIGHT;

#endif







