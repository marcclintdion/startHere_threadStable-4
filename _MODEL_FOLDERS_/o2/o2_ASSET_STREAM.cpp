#ifdef WIN32 
void load_o2_FromHDtoSystemRAM(void*) 
{                                                                           
    fifmt_o2 = FreeImage_GetFileType(o2_FilePath, 0);                       
    dib_o2   = FreeImage_Load(fifmt_o2, o2_FilePath, 0);                    
    temp_o2  = dib_o2;                                                      
    dib_o2   = FreeImage_ConvertTo32Bits(temp_o2);                          
    FreeImage_Unload(temp_o2);                                            

    if( dib_o2 != NULL )                                                    
    {                                                                       
        pixels_o2 = (BYTE*)FreeImage_GetBits(dib_o2);                       
    }                                                                     

    o2_isLoadedFromDriveAndWaiting = true;                                  
    //---------------------                                                 
    if(MAX_THREADS > 0)                                                     
    {                                                                       
         MAX_THREADS -= 1;                                                  
    }                                                                       
    //---------------------                                                 
    _endthread();                                                           
}                                                                           
//----------------------------------------------------------                
void delete_o2_FromSystemRAM(void)                                          
{                                                                           
    if( dib_o2 != NULL )                                                    
    {                                                                       
        free(pixels_o2);                                                    
        FreeImage_Unload(dib_o2);                                           
    }                                                                     

}                                                                           
//==========================================================                
#endif                                                                      
