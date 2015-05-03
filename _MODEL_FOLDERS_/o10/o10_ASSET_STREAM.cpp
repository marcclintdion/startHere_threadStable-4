#ifdef WIN32 
void load_o10_FromHDtoSystemRAM(void*) 
{                                                                           
    fifmt_o10 = FreeImage_GetFileType(o10_FilePath, 0);                       
    dib_o10   = FreeImage_Load(fifmt_o10, o10_FilePath, 0);                    
    temp_o10  = dib_o10;                                                      
    dib_o10   = FreeImage_ConvertTo32Bits(temp_o10);                          
    FreeImage_Unload(temp_o10);                                            

    if( dib_o10 != NULL )                                                    
    {                                                                       
        pixels_o10 = (BYTE*)FreeImage_GetBits(dib_o10);                       
    }                                                                     

    o10_isLoadedFromDriveAndWaiting = true;                                  
    //---------------------                                                 
    if(MAX_THREADS > 0)                                                     
    {                                                                       
         MAX_THREADS -= 1;                                                  
    }                                                                       
    //---------------------                                                 
    _endthread();                                                           
}                                                                           
//----------------------------------------------------------                
void delete_o10_FromSystemRAM(void)                                          
{                                                                           
    if( dib_o10 != NULL )                                                    
    {                                                                       
        free(pixels_o10);                                                    
        FreeImage_Unload(dib_o10);                                           
    }                                                                     

}                                                                           
//==========================================================                
#endif                                                                      
