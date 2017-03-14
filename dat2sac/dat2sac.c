
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define PI 3.14159265358979



struct sacheader{
  double DELTA;
  double DEPMIN;
  double DEPMAX;
  double SCALE;
  double ODELTA;
  double B;
  double E;
  double O;
  double A;
  double H9;
  double T0;
  double T1;
  double T2;
  double T3;
  double T4;
  double T5;
  double T6;
  double T7;
  double T8;
  double T9;
  double F;
  double RESP0;
  double RESP1;
  double RESP2;
  double RESP3;
  double RESP4;
  double RESP5;
  double RESP6;
  double RESP7;
  double RESP8;
  double RESP9;
  double STLA;
  double STLO;
  double STEL;
  double STDP;
  double EVLA;
  double EVLO;
  double EVEL;
  double EVDP;
  double H39;
  double USER0;
  double USER1;
  double USER2;
  double USER3;
  double USER4;
  double USER5;
  double USER6;
  double USER7;
  double USER8;
  double USER9;
  double DIST;
  double AZ;
  double BAZ;
  double GCARC;
  double H54;
  double H55;
  double DEPMEN;
  double CMPAZ;
  double CMPINC;
  double H59;
  double H60;
  double H61;
  double H62;
  double H63;
  double H64;
  double H65;
  double H66;
  double H67;
  double H68;
  double H69;
  long NZYEAR;
  long NZJDAY;
  long NZHOUR;
  long NZMIN;
  long NZSEC;
  long NZMSEC;
  long NVHDR;
  long H77;
  long H78;
  long NPTS;
  long H80;
  long H81;
  long H82;
  long H83;
  long H84;
  long IFTYPE;
  long IDEP;
  long IZTYPE;
  long H88;
  long H89;
  long ISTREG;
  long IEVREG;
  long IEVTYP;
  long IQUAL;
  long ISYNTH;
  long H95;
  long H96;
  long H97;
  long H98;
  long H99;
  long H100;
  long H101;
  long H102;
  long H103;
  long H104;
  long LEVEN;
  long LPSPOL;
  long LOVROK;
  long LCALDA;
  long H109;
  char KSTNM[9];
  char KEVNM[17];
  char KHOLE[9];
  char KO[9];
  char KA[9];
  char KT0[9];
  char KT1[9];
  char KT2[9];
  char KT3[9];
  char KT4[9];
  char KT5[9];
  char KT6[9];
  char KT7[9];
  char KT8[9];
  char KT9[9];
  char KF[9];
  char KUSER0[9];
  char KUSER1[9];
  char KUSER2[9];
  char KCMPNM[9];
  char KNETWK[9];
  char KDATRD[9];
  char KINST[9];
};


int newsacheader(struct sacheader *hv);
int writesac(char *sacfile, struct sacheader *hv, double *sacdata);

int main(int argc, char *argv[])
{
  
  if(argc != 5){
    printf("Useage: dat2sac DATFILE SACFILE DELTA NP\n");
    exit(1);
  }

  char input[256], output[256], buf[256],deltastr[20], npstr[20];
  double *x, *y, delta;
  double *xd,*yd;
  long np=0, nerr=0, i=0;
  FILE *fp;
  struct sacheader hv;


  strcpy(input, argv[1]);
  strcpy(output, argv[2]);
  strcpy(deltastr,argv[3]);
  strcpy(npstr,argv[4]);
  delta = atof(deltastr);
  np = atol(npstr);
  
  if(!(fp=fopen(input,"r"))){
    printf("File Open Error.\n");
    exit(1);
  }
  /* 
  np =0;

  fscanf(fp, "%ld\n", &np);
  printf ("length=%ld\n",np);
  */

  x = (double *)calloc((size_t)np, sizeof(double));
  y = (double *)calloc((size_t)np, sizeof(double));

  xd = (double *)calloc((size_t)np, sizeof(double));
  yd = (double *)calloc((size_t)np, sizeof(double));

  

  for(i=0; i<np; i++){
    fscanf(fp, "%lf\n", &yd[i]);
    /*x[i] = (float) xd;*/
    printf("%lf\n",yd[i]);

  }
  fclose(fp); 
  

  x[0] = 0.e0;
  x[np-1] = delta*(double)(np-1);
  newsacheader(&hv);
  hv.NPTS = np; 
  hv.B = x[0];
  hv.E = x[np-1];
  hv.DELTA=(double)delta;
  
  /*
  delta = x[1] - x[0];
  
  newhdr();
  setnhv("NPTS", &np, &nerr, 4);
  setfhv("B", &x[0], &nerr, 1);
  setfhv("E", &x[np-1], &nerr, 1);
  setfhv("DELTA", &delta, &nerr, 5);
  wsac0(output, x, y, &nerr, (long)strlen(output));
  */

  writesac(output, &hv, yd);

  return (0);
}



int newsacheader(struct sacheader *hv)
{
  /* Thank you UCHIDE-san */

  hv->DELTA = -12345.0;
  hv->DEPMIN = -12345.0;
  hv->DEPMAX = -12345.0;
  hv->SCALE = -12345.0;
  hv->ODELTA = -12345.0;
  hv->B = -12345.0;
  hv->E = -12345.0;
  hv->O = -12345.0;
  hv->A = -12345.0;
  hv->H9 = -12345.0;
  hv->T0 = -12345.0;
  hv->T1 = -12345.0;
  hv->T2 = -12345.0;
  hv->T3 = -12345.0;
  hv->T4 = -12345.0;
  hv->T5 = -12345.0;
  hv->T6 = -12345.0;
  hv->T7 = -12345.0;
  hv->T8 = -12345.0;
  hv->T9 = -12345.0;
  hv->F = -12345.0;
  hv->RESP0 = -12345.0;
  hv->RESP1 = -12345.0;
  hv->RESP2 = -12345.0;
  hv->RESP3 = -12345.0;
  hv->RESP4 = -12345.0;
  hv->RESP5 = -12345.0;
  hv->RESP6 = -12345.0;
  hv->RESP7 = -12345.0;
  hv->RESP8 = -12345.0;
  hv->RESP9 = -12345.0;
  hv->STLA  = -12345.0;
  hv->STLO  = -12345.0;
  hv->STEL  = -12345.0;
  hv->STDP  = -12345.0;
  hv->EVLA  = -12345.0;
  hv->EVLO  = -12345.0;
  hv->EVEL  = -12345.0;
  hv->EVDP  = -12345.0;
  hv->H39   = -12345.0;
  hv->USER0 = -12345.0;
  hv->USER1 = -12345.0;
  hv->USER2 = -12345.0;
  hv->USER3 = -12345.0;
  hv->USER4 = -12345.0;
  hv->USER5 = -12345.0;
  hv->USER6 = -12345.0;
  hv->USER7 = -12345.0;
  hv->USER8 = -12345.0;
  hv->USER9 = -12345.0;
  hv->DIST = -12345.0;
  hv->AZ   = -12345.0;
  hv->BAZ  = -12345.0;
  hv->GCARC= -12345.0;;
  hv->H54  = -12345.0;
  hv->H55  = -12345.0;
  hv->DEPMEN = -12345.0;
  hv->CMPAZ = -12345.0;
  hv->CMPINC = -12345.0;
  hv->H59 = -12345.0;
  hv->H60 = -12345.0;
  hv->H61 = -12345.0;
  hv->H62 = -12345.0;
  hv->H63 = -12345.0;
  hv->H64 = -12345.0;
  hv->H65 = -12345.0;
  hv->H66 = -12345.0;
  hv->H67 = -12345.0;
  hv->H68 = -12345.0;
  hv->H69 = -12345.0;
  hv->NZYEAR = -12345;
  hv->NZJDAY = -12345;
  hv->NZHOUR = -12345;
  hv->NZMIN = -12345;
  hv->NZSEC = -12345;
  hv->NZMSEC = -12345;
  hv->NVHDR = 6;
  hv->H77 = -12345;
  hv->H78 = -12345;
  hv->NPTS = -12345;
  hv->H80 = -12345;
  hv->H81 = -12345;
  hv->H82 = -12345;
  hv->H83 = -12345;
  hv->H84 = -12345;
  hv->IFTYPE = 1;
  hv->IDEP = 7;
  hv->IZTYPE = -12345;
  hv->H88 = -12345;
  hv->H89 = -12345;
  hv->ISTREG = -12345;
  hv->IEVREG = -12345;
  hv->IEVTYP = -12345;
  hv->IQUAL = -12345;
  hv->ISYNTH = -12345;
  hv->H95 = -12345;
  hv->H96 = -12345;
  hv->H97 = -12345;
  hv->H98 = -12345;
  hv->H99 = -12345;
  hv->H100= -12345;
  hv->H101= -12345;
  hv->H102= -12345;
  hv->H103= -12345;
  hv->H104= -12345;
  hv->LEVEN = 1;
  hv->LPSPOL = 0;
  hv->LOVROK = 1;
  hv->LCALDA = 1;
  hv->H109 = -12345;
  strcpy(hv->KSTNM, "-12345");
  strcpy(hv->KEVNM,"-12345");
  strcpy(hv->KHOLE, "-12345");
  strcpy(hv->KO, "-12345");
  strcpy(hv->KA, "-12345");
  strcpy(hv->KT0,"-12345");
  strcpy(hv->KT1,"-12345");
  strcpy(hv->KT2,"-12345");
  strcpy(hv->KT3,"-12345");
  strcpy(hv->KT4,"-12345");
  strcpy(hv->KT5,"-12345");
  strcpy(hv->KT6,"-12345");
  strcpy(hv->KT7,"-12345");
  strcpy(hv->KT8,"-12345");
  strcpy(hv->KT9,"-12345");
  strcpy(hv->KF,"-12345");
  strcpy(hv->KUSER0,"-12345");
  strcpy(hv->KUSER1,"-12345");
  strcpy(hv->KUSER2,"-12345");
  strcpy(hv->KCMPNM,"-12345");
  strcpy(hv->KNETWK,"-12345");
  strcpy(hv->KDATRD,"-12345");
  strcpy(hv->KINST,"-12345");

  return 0;

}




int writesac(char *sacfile, struct sacheader *hv, double *sacdata)
{
  FILE *fp;
  fp = fopen(sacfile, "w");
  float ftmp[70],tmpfloat;
  long i;
  char ch;
  char tmpchar[9],tmpchar2[17];
  
  ftmp[0]=(float)hv->DELTA;
  ftmp[1]=(float)hv->DEPMIN;
  ftmp[2]=(float)hv->DEPMAX;
  ftmp[3]=(float)hv->SCALE;
  ftmp[4]=(float)hv->ODELTA;
  ftmp[5]=(float)hv->B;
  ftmp[6]=(float)hv->E;
  ftmp[7]=(float)hv->O;
  ftmp[8]=(float)hv->A;
  ftmp[9]=(float)hv->H9;
  ftmp[10]=(float)hv->T0;
  ftmp[11]=(float)hv->T1;
  ftmp[12]=(float)hv->T2;
  ftmp[13]=(float)hv->T3;
  ftmp[14]=(float)hv->T4;
  ftmp[15]=(float)hv->T5;
  ftmp[16]=(float)hv->T6;
  ftmp[17]=(float)hv->T7;
  ftmp[18]=(float)hv->T8;
  ftmp[19]=(float)hv->T9;
  ftmp[20]=(float)hv->F;
  ftmp[21]=(float)hv->RESP0;
  ftmp[22]=(float)hv->RESP1;
  ftmp[23]=(float)hv->RESP2;
  ftmp[24]=(float)hv->RESP3;
  ftmp[25]=(float)hv->RESP4;
  ftmp[26]=(float)hv->RESP5;
  ftmp[27]=(float)hv->RESP6;
  ftmp[28]=(float)hv->RESP7;
  ftmp[29]=(float)hv->RESP8;
  ftmp[30]=(float)hv->RESP9;
  ftmp[31]=(float)hv->STLA;
  ftmp[32]=(float)hv->STLO;
  ftmp[33]=(float)hv->STEL;
  ftmp[34]=(float)hv->STDP;
  ftmp[35]=(float)hv->EVLA;
  ftmp[36]=(float)hv->EVLO;
  ftmp[37]=(float)hv->EVEL;
  ftmp[38]=(float)hv->EVDP;
  ftmp[39]=(float)hv->H39;
  ftmp[40]=(float)hv->USER0;
  ftmp[41]=(float)hv->USER1;
  ftmp[42]=(float)hv->USER2;
  ftmp[43]=(float)hv->USER3;
  ftmp[44]=(float)hv->USER4;
  ftmp[45]=(float)hv->USER5;
  ftmp[46]=(float)hv->USER6;
  ftmp[47]=(float)hv->USER7;
  ftmp[48]=(float)hv->USER8;
  ftmp[49]=(float)hv->USER9;
  ftmp[50]=(float)hv->DIST;
  ftmp[51]=(float)hv->AZ;
  ftmp[52]=(float)hv->BAZ;
  ftmp[53]=(float)hv->GCARC;
  ftmp[54]=(float)hv->H54;
  ftmp[55]=(float)hv->H55;
  ftmp[56]=(float)hv->DEPMEN;
  ftmp[57]=(float)hv->CMPAZ;
  ftmp[58]=(float)hv->CMPINC;
  ftmp[59]=(float)hv->H59;
  ftmp[60]=(float)hv->H60;
  ftmp[61]=(float)hv->H61;
  ftmp[62]=(float)hv->H62;
  ftmp[63]=(float)hv->H63;
  ftmp[64]=(float)hv->H64;
  ftmp[65]=(float)hv->H65;
  ftmp[66]=(float)hv->H66;
  ftmp[67]=(float)hv->H67;
  ftmp[68]=(float)hv->H68;
  ftmp[69]=(float)hv->H69;
  fwrite(ftmp,4,70,fp);
  fwrite(&hv->NZYEAR,4,1,fp);
  fwrite(&hv->NZJDAY,4,1,fp);
  fwrite(&hv->NZHOUR,4,1,fp);
  fwrite(&hv->NZMIN,4,1,fp);
  fwrite(&hv->NZSEC,4,1,fp);
  fwrite(&hv->NZMSEC,4,1,fp);
  fwrite(&hv->NVHDR,4,1,fp);
  fwrite(&hv->H77,4,1,fp);
  fwrite(&hv->H78,4,1,fp);
  fwrite(&hv->NPTS,4,1,fp);
  fwrite(&hv->H80,4,1,fp);
  fwrite(&hv->H81,4,1,fp);
  fwrite(&hv->H82,4,1,fp);
  fwrite(&hv->H83,4,1,fp);
  fwrite(&hv->H84,4,1,fp);
  fwrite(&hv->IFTYPE,4,1,fp);
  fwrite(&hv->IDEP,4,1,fp);
  fwrite(&hv->IZTYPE,4,1,fp);
  fwrite(&hv->H88,4,1,fp);
  fwrite(&hv->H89,4,1,fp);
  fwrite(&hv->ISTREG,4,1,fp);
  fwrite(&hv->IEVREG,4,1,fp);
  fwrite(&hv->IEVTYP,4,1,fp);
  fwrite(&hv->IQUAL,4,1,fp);
  fwrite(&hv->ISYNTH,4,1,fp);
  fwrite(&hv->H95,4,1,fp);
  fwrite(&hv->H96,4,1,fp);
  fwrite(&hv->H97,4,1,fp);
  fwrite(&hv->H98,4,1,fp);
  fwrite(&hv->H99,4,1,fp);
  fwrite(&hv->H100,4,1,fp);
  fwrite(&hv->H101,4,1,fp);
  fwrite(&hv->H102,4,1,fp);
  fwrite(&hv->H103,4,1,fp);
  fwrite(&hv->H104,4,1,fp);
  fwrite(&hv->LEVEN,4,1,fp);
  fwrite(&hv->LPSPOL,4,1,fp);
  fwrite(&hv->LOVROK,4,1,fp);
  fwrite(&hv->LCALDA,4,1,fp);
  fwrite(&hv->H109,4,1,fp);

  strcpy(tmpchar, hv->KSTNM);
  for(i=0;i<8;i++){
    ch=tmpchar[i];
    fwrite(&ch, 1,1,fp);
  }
  
  strcpy(tmpchar2, hv->KEVNM);
  for(i=0;i<16;i++){
    ch=tmpchar2[i];
    fwrite(&ch, 1,1,fp);
  }

  strcpy(tmpchar, hv->KHOLE);
  for(i=0;i<8;i++){
    ch=tmpchar[i];
    fwrite(&ch, 1,1,fp);
  }
  
  strcpy(tmpchar, hv->KO);
  for(i=0;i<8;i++){
    ch=tmpchar[i];
    fwrite(&ch, 1,1,fp);
  }
  
  strcpy(tmpchar, hv->KA);
  for(i=0;i<8;i++){
    ch=tmpchar[i];
    fwrite(&ch, 1,1,fp);
  }
  
  strcpy(tmpchar, hv->KT0);
  for(i=0;i<8;i++){
    ch=tmpchar[i];
    fwrite(&ch, 1,1,fp);
  }
  
  strcpy(tmpchar, hv->KT1);
  for(i=0;i<8;i++){
    ch=tmpchar[i];
    fwrite(&ch, 1,1,fp);
    tmpchar[i]=ch;
  }
  
  strcpy(tmpchar, hv->KT2);
  for(i=0;i<8;i++){
    ch=tmpchar[i];
    fwrite(&ch, 1,1,fp);
  }
  
  strcpy(tmpchar, hv->KT3);
  for(i=0;i<8;i++){
    ch=tmpchar[i];
    fwrite(&ch, 1,1,fp);
  }
  
  strcpy(tmpchar, hv->KT4);
  for(i=0;i<8;i++){
    ch=tmpchar[i];
    fwrite(&ch, 1,1,fp);
  }
  
  strcpy(tmpchar, hv->KT5);
  for(i=0;i<8;i++){
    ch=tmpchar[i];
    fwrite(&ch, 1,1,fp);
  }
  
  strcpy(tmpchar, hv->KT6);
  for(i=0;i<8;i++){
    ch=tmpchar[i];
    fwrite(&ch, 1,1,fp);
  }
  
  strcpy(tmpchar, hv->KT7);
  for(i=0;i<8;i++){
    ch=tmpchar[i];
    fwrite(&ch, 1,1,fp);
  }
  
  strcpy(tmpchar, hv->KT8);
  for(i=0;i<8;i++){
    ch=tmpchar[i];
    fwrite(&ch, 1,1,fp);
  }
  
  strcpy(tmpchar, hv->KT9);
  for(i=0;i<8;i++){
    ch=tmpchar[i];
    fwrite(&ch, 1,1,fp);
  }
  
  strcpy(tmpchar, hv->KF);
  for(i=0;i<8;i++){
    ch=tmpchar[i];
    fwrite(&ch, 1,1,fp);
  }
  
  strcpy(tmpchar, hv->KUSER0);
  for(i=0;i<8;i++){
    ch=tmpchar[i];
    fwrite(&ch, 1,1,fp);
  }
  
  strcpy(tmpchar, hv->KUSER1);  
  for(i=0;i<8;i++){
    ch=tmpchar[i];
    fwrite(&ch, 1,1,fp);
  }
  
  strcpy(tmpchar, hv->KUSER2);
  for(i=0;i<8;i++){
    ch=tmpchar[i];
    fwrite(&ch, 1,1,fp);
  }
  
  strcpy(tmpchar, hv->KCMPNM);  
  for(i=0;i<8;i++){
    ch=tmpchar[i];
    fwrite(&ch, 1,1,fp);
    tmpchar[i]=ch;
  }
  
  strcpy(tmpchar, hv->KNETWK);
  for(i=0;i<8;i++){
    ch=tmpchar[i];
    fwrite(&ch, 1,1,fp);
  }
  
  strcpy(tmpchar, hv->KDATRD);
  for(i=0;i<8;i++){
    ch=tmpchar[i];
    fwrite(&ch, 1,1,fp);
  }
  
  strcpy(tmpchar, hv->KINST);
  for(i=0;i<8;i++){
    ch=tmpchar[i];
    fwrite(&ch, 1,1,fp);
  }


  for(i=0;i<hv->NPTS;i++){
    tmpfloat = (float)sacdata[i];
    fwrite(&tmpfloat,4,1,fp);
  }
   
  return(0);
}

