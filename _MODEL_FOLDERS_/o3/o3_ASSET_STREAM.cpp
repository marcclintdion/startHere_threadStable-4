#ifdef WIN32 
void load_o3_FromHDtoSystemRAM(void*) 
{                                                                           
    fifmt_o3 = FreeImage_GetFileType(o3_FilePath, 0);                       
    dib_o3   = FreeImage_Load(fifmt_o3, o3_FilePath, 0);                    
    temp_o3  = dib_o3;                                                      
    dib_o3   = FreeImage_ConvertTo32Bits(temp_o3);                          
    FreeImage_Unload(temp_o3);                                            

    if( dib_o3 != NULL )                                                    
    {                                                                       
        pixels_o3 = (BYTE*)FreeImage_GetBits(dib_o3);                       
    }                                                                     

    o3_isLoadedFromDriveAndWaiting = true;                                  
    //---------------------                                                 
    if(MAX_THREADS > 0)                                                     
    {                                                                       
         MAX_THREADS -= 1;                                                  
    }                                                                       
    //---------------------                                                 
    _endthread();                                                           
}                                                                           
//----------------------------------------------------------                
void delete_o3_FromSystemRAM(void)                                          
{                                                                           
    if( dib_o3 != NULL )                                                    
    {                                                                       
        free(pixels_o3);                                                    
        FreeImage_Unload(dib_o3);                                           
    }                                                                     

}                                                                           
//==========================================================                
#endif                                                                      
