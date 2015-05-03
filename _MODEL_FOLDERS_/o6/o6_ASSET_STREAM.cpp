#ifdef WIN32 
void load_o6_FromHDtoSystemRAM(void*) 
{                                                                           
    fifmt_o6 = FreeImage_GetFileType(o6_FilePath, 0);                       
    dib_o6   = FreeImage_Load(fifmt_o6, o6_FilePath, 0);                    
    temp_o6  = dib_o6;                                                      
    dib_o6   = FreeImage_ConvertTo32Bits(temp_o6);                          
    FreeImage_Unload(temp_o6);                                            

    if( dib_o6 != NULL )                                                    
    {                                                                       
        pixels_o6 = (BYTE*)FreeImage_GetBits(dib_o6);                       
    }                                                                     

    o6_isLoadedFromDriveAndWaiting = true;                                  
    //---------------------                                                 
    if(MAX_THREADS > 0)                                                     
    {                                                                       
         MAX_THREADS -= 1;                                                  
    }                                                                       
    //---------------------                                                 
    _endthread();                                                           
}                                                                           
//----------------------------------------------------------                
void delete_o6_FromSystemRAM(void)                                          
{                                                                           
    if( dib_o6 != NULL )                                                    
    {                                                                       
        free(pixels_o6);                                                    
        FreeImage_Unload(dib_o6);                                           
    }                                                                     

}                                                                           
//==========================================================                
#endif                                                                      
