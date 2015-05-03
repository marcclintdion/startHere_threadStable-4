#ifdef WIN32 
void load_deadForest_FromHDtoSystemRAM(void*) 
{                                                           
    fifmt_deadForest = FreeImage_GetFileType(deadForest_FilePath, 0);       
    dib_deadForest   = FreeImage_Load(fifmt_deadForest, deadForest_FilePath, 0);    
    temp_deadForest  = dib_deadForest;                                      
    dib_deadForest   = FreeImage_ConvertTo32Bits(temp_deadForest);          
    FreeImage_Unload(temp_deadForest);                            

    if( dib_deadForest != NULL )                                    
    {                                                       
        pixels_deadForest = (BYTE*)FreeImage_GetBits(dib_deadForest);       
    }                                                     

    deadForest_isLoadedFromDriveAndWaiting = true;                  
    _endthread();                                           
}                                                           
//==========================================================
void delete_deadForest_FromSystemRAM(void)                          
{                                                           
    if( dib_deadForest != NULL )                                    
    {                                                       
        free(pixels_deadForest);                                    
        FreeImage_Unload(dib_deadForest);                           
    }                                                     

}                                                           
#endif                                                      
