$ImageVersion = 1.0
$ImageName = "e6r4de7ly3x6ws3g/txt-controller-toolchain:$ImageVersion"

docker build -t $ImageName .
docker login
docker push $ImageName