#ifdef WIN32 
void load_copperEntrance_FromHDtoSystemRAM(void*) 
{                                                                           
    fifmt_copperEntrance = FreeImage_GetFileType(copperEntrance_FilePath, 0);                       
    dib_copperEntrance   = FreeImage_Load(fifmt_copperEntrance, copperEntrance_FilePath, 0);                    
    temp_copperEntrance  = dib_copperEntrance;                                                      
    dib_copperEntrance   = FreeImage_ConvertTo32Bits(temp_copperEntrance);                          
    FreeImage_Unload(temp_copperEntrance);                                            

    if( dib_copperEntrance != NULL )                                                    
    {                                                                       
        pixels_copperEntrance = (BYTE*)FreeImage_GetBits(dib_copperEntrance);                       
    }                                                                     

    copperEntrance_isLoadedFromDriveAndWaiting = true;                                  
    //---------------------                                                 
    if(MAX_THREADS > 0)                                                     
    {                                                                       
         MAX_THREADS -= 1;                                                  
    }                                                                       
    //---------------------                                                 
    _endthread();                                                           
}                                                                           
//----------------------------------------------------------                
void delete_copperEntrance_FromSystemRAM(void)                                          
{                                                                           
    if( dib_copperEntrance != NULL )                                                    
    {                                                                       
        free(pixels_copperEntrance);                                                    
        FreeImage_Unload(dib_copperEntrance);                                           
    }                                                                     

}                                                                           
//==========================================================                
#endif                                                                      
