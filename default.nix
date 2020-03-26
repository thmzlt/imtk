{ pkgs ? import (fetchTarball https://github.com/nixos/nixpkgs-channels/archive/3a84353edb56a6167fb687f2fdc32cab48a65079.tar.gz) {} }:

pkgs.llvmPackages_9.stdenv.mkDerivation {
  name = "imtk";
  version = "0.1.0";

  src = ./.;

  nativeBuildInputs = with pkgs; [
    cmake
  ];

  buildInputs = with pkgs; [
    clang-tools
    libglvnd
    ninja
    sfml
  ];
}
