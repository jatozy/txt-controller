$ImageVersion = 1.0
$ImageNamePrefix = "e6r4de7ly3x6ws3g/txt-controller-toolchain"
$ImageName = "${ImageNamePrefix}:${ImageVersion}"
$ImageNameLatest = "${ImageNamePrefix}:latest"

docker build -t $ImageName .
docker tag $ImageName $ImageNameLatest
docker login
docker push $ImageName
docker push $ImageNameLatest
