using System;
using System.Collections;
using System.Collections.Generic;
using System.IO;

namespace challenge2 {
	class Program {
		static string[] Lines {get; set;}
		static List<Claim> Claims {get; set;}

		static void Main(string[] args) {
			Claims = new List<Claim>();
			Console.WriteLine("Reading input.txt");
			Lines = File.ReadAllLines("./input.txt");
			foreach (string line in Lines) {
				Claim current = new Claim(line);
				Claims.Add(current);
				current.Print();
			}
			Fabric fabric = new Fabric(Claims);
			Console.WriteLine("Found ID: " + fabric.CalculateOverlaps());
		}

		public static void printArray(string[] arr) {
			foreach (string str in arr) {
				Console.WriteLine(str);
			}
		}
	}

	class Claim {
		public int ID {get; set;}
		public int X {get; set;}
		public int Y {get; set;}
		public int W {get; set;}
		public int H {get; set;}
		public string Source {get; set;}

		public Claim(string source) {
			this.Source = source;
			ParseSource();
		}

		private void ParseSource() {
			Console.WriteLine("Parsing: " + this.Source);
			string[] source = this.Source.Split('#');
			string[] idAndRest = source[1].Split('@');
			this.ID = int.Parse(idAndRest[0]);
			string[] fromSides = idAndRest[1].Split(',');
			string[] afterColon = fromSides[1].Split(':');
			this.X = int.Parse(fromSides[0]);
			this.Y = int.Parse(afterColon[0]);
			string[] dimensions = afterColon[1].Split('x');
			this.W = int.Parse(dimensions[0]);
			this.H = int.Parse(dimensions[1]);
		}

		public void Print() {
			Console.WriteLine("Claim ID: " + this.ID);
			Console.WriteLine("X, Y: " + this.X + ',' + this.Y);
			Console.WriteLine("Dimensions: " + this.W + 'x' + this.H);
			Console.WriteLine("Parsed from source: " + this.Source);
			Console.WriteLine();
		}
	}

	class Fabric {
		public List<Claim> Claims;

		private int[,] Board;

		public Fabric(List<Claim> claims) {
			this.Claims = claims;
			this.Board = new int[10000, 10000];

			for (int i = 0; i < 10000; i++) {
				for (int j = 0; j < 10000; j++) {
					Board[i, j] = 0;
				}
			}
		}

		public int CalculateOverlaps() {
			int overlaps = 0;

			foreach (Claim claim in this.Claims) {
				for (int x = claim.X; x < claim.X + claim.W; x++) {
					for (int y = claim.Y; y < claim.Y + claim.H; y++) {
						Board[x, y]++;
					}
				}
			}

			foreach (Claim claim in this.Claims) {
				bool isValid = true;
				Console.WriteLine("Processing claim ID: " + claim.ID);

				for (int x = claim.X; x < claim.X + claim.W; x++) {
					for (int y = claim.Y; y < claim.Y + claim.H; y++) {
						if(this.Board[x,y] != 1) {
							isValid = false;
							break;
						}
					}
					if (!isValid) break;
				}
				if (isValid) {
					overlaps = claim.ID;
					break;
				}
			}
			return overlaps;
		}
	}
}
