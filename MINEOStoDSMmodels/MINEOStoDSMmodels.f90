program modelConverter
  ! Nobuaki Fuji for DSM Kernel
  !  July 2016, Institut de Physique du Globe de Paris
  !  Mars 2017 
  
  use parameters
  implicit none
  integer :: i,j,k,kmax,iirlength
  double precision, allocatable, dimension (:,:) :: a,at,ata,atainv
  double precision, allocatable, dimension (:) :: tmparray,tmparray2
  double precision :: rnormalised1,rnormalised2,coef
  integer :: liquidlayers
  
  call getarg(1,model1d)
  model1d = trim(model1d)
  call getarg(2,psvmodel)
  psvmodel = trim(psvmodel)
  call getarg(3,shmodel)
  shmodel = trim(shmodel)

  call readMINEOScard

  print *, psvmodel,shmodel
  
  nzone = 0
  liquidlayers = 0
  
  do i = 1,nrmod-1
     if(rmod(i).ne.rmod(i+1)) nzone = nzone +1
  enddo

  allocate(vrmin(1:nzone),vrmax(1:nzone),irmin(1:nzone),irmax(1:nzone),irlength(1:nzone),qmuD(1:nzone),qkappaD(1:nzone))
  allocate(rrhoD(1:4,1:nzone),vpvD(1:4,1:nzone),vphD(1:4,1:nzone),vsvD(1:4,1:nzone),vshD(1:4,1:nzone),etaD(1:4,1:nzone))

  
  j = 1
  vrmin(j) = rmod(1)
  irmin(j) = 1

  ! NF here, we use only linear interpolation

  rrhoD = 0.d0
  vpvD = 0.d0
  vphD = 0.d0
  vsvD = 0.d0
  vshD = 0.d0


  
  do i = 1,nrmod-1
     
     if(rmod(i).ne.rmod(i+1)) then
        irmax(j) = i+1
        vrmax(j) = rmod(i+1)
        ! NF in DSM, qmu and qkappa are constant through one zone
        qmuD(j) = qm(i)
        qkappaD(j) = qk(i)
        etaD(1,j) = 1.d0
        ! NF can of course change this easily though ...
        
        irmin(j) = i
        vrmin(j) = rmod(i)

        rnormalised1 = rmod(i)/rmod(nrmod)
        rnormalised2 = rmod(i+1)/rmod(nrmod)
        
        rrhoD(2,j)=(dnm(i+1)-dnm(i))/(rnormalised2-rnormalised1)
        rrhoD(1,j)=dnm(i)-rrhoD(2,j)*rnormalised1

        vsvD(2,j)=(vsv(i+1)-vsv(i))/(rnormalised2-rnormalised1)
        vsvD(1,j)=vsv(i)-vsvD(2,j)*rnormalised1
        
        vshD(2,j)=(vsh(i+1)-vsh(i))/(rnormalised2-rnormalised1)
        vshD(1,j)=vsh(i)-vshD(2,j)*rnormalised1


        vpvD(2,j)=(vpv(i+1)-vpv(i))/(rnormalised2-rnormalised1)
        vpvD(1,j)=vpv(i)-vpvD(2,j)*rnormalised1
        
        vphD(2,j)=(vph(i+1)-vph(i))/(rnormalised2-rnormalised1)
        vphD(1,j)=vph(i)-vphD(2,j)*rnormalised1

       
        
        if(vsh(i).eq.0.d0) liquidlayers = j

         j=j+1
     endif
  enddo
 

  call writepsvmodel
  nzone=nzone-liquidlayers

  vrmin(1:nzone)=vrmin(liquidlayers+1:liquidlayers+nzone)
  vrmax(1:nzone)=vrmax(liquidlayers+1:liquidlayers+nzone)
  rrhoD(:,1:nzone)=rrhoD(:,liquidlayers+1:liquidlayers+nzone)
  vsvD(:,1:nzone)=vsvD(:,liquidlayers+1:liquidlayers+nzone)
  vshD(:,1:nzone)=vshD(:,liquidlayers+1:liquidlayers+nzone)
  qmuD(1:nzone)=qmuD(liquidlayers+1:liquidlayers+nzone)
  call writeshmodel
        
end program modelConverter
  
  
  

  

  
