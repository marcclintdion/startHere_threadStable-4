#ifdef WIN32 
void load_o9_FromHDtoSystemRAM(void*) 
{                                                                           
    fifmt_o9 = FreeImage_GetFileType(o9_FilePath, 0);                       
    dib_o9   = FreeImage_Load(fifmt_o9, o9_FilePath, 0);                    
    temp_o9  = dib_o9;                                                      
    dib_o9   = FreeImage_ConvertTo32Bits(temp_o9);                          
    FreeImage_Unload(temp_o9);                                            

    if( dib_o9 != NULL )                                                    
    {                                                                       
        pixels_o9 = (BYTE*)FreeImage_GetBits(dib_o9);                       
    }                                                                     

    o9_isLoadedFromDriveAndWaiting = true;                                  
    //---------------------                                                 
    if(MAX_THREADS > 0)                                                     
    {                                                                       
         MAX_THREADS -= 1;                                                  
    }                                                                       
    //---------------------                                                 
    _endthread();                                                           
}                                                                           
//----------------------------------------------------------                
void delete_o9_FromSystemRAM(void)                                          
{                                                                           
    if( dib_o9 != NULL )                                                    
    {                                                                       
        free(pixels_o9);                                                    
        FreeImage_Unload(dib_o9);                                           
    }                                                                     

}                                                                           
//==========================================================                
#endif                                                                      
