#ifdef WIN32 
void load_Plane_FromHDtoSystemRAM(void*) 
{                                                                           
    fifmt_Plane = FreeImage_GetFileType(Plane_FilePath, 0);                       
    dib_Plane   = FreeImage_Load(fifmt_Plane, Plane_FilePath, 0);                    
    temp_Plane  = dib_Plane;                                                      
    dib_Plane   = FreeImage_ConvertTo32Bits(temp_Plane);                          
    FreeImage_Unload(temp_Plane);                                            

    if( dib_Plane != NULL )                                                    
    {                                                                       
        pixels_Plane = (BYTE*)FreeImage_GetBits(dib_Plane);                       
    }                                                                     

    Plane_isLoadedFromDriveAndWaiting = true;                                  
    //---------------------                                                 
    if(MAX_THREADS > 0)                                                     
    {                                                                       
         MAX_THREADS -= 1;                                                  
    }                                                                       
    //---------------------                                                 
    _endthread();                                                           
}                                                                           
//----------------------------------------------------------                
void delete_Plane_FromSystemRAM(void)                                          
{                                                                           
    if( dib_Plane != NULL )                                                    
    {                                                                       
        free(pixels_Plane);                                                    
        FreeImage_Unload(dib_Plane);                                           
    }                                                                     

}                                                                           
//==========================================================                
#endif                                                                      
